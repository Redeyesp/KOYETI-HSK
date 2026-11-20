#include "Application.h"
#include "ChineseFont.h"
#include "config.h"

namespace
{
enum class HeartAnimation : uint8_t
{
    None,
    Heart1A,
    Heart2A,
    Heart1B,
    Heart2B
};

HeartAnimation heartAnimation = HeartAnimation::None;
unsigned long heartFrameStartedMs = 0;

constexpr unsigned long HEART_SMALL_MS = 300;
constexpr unsigned long HEART_BIG_MS = 440;
constexpr unsigned long SLEEP_Z_SLOW_MS = 420;

// Each blink gets its own speed so KOYETI feels less mechanical.
unsigned long blinkHalfMs = 70;
unsigned long blinkClosedMs = 100;

void chooseBlinkTiming()
{
    const uint8_t roll = random(100);

    if (roll < 30)
    {
        // Quick blink
        blinkHalfMs = 40;
        blinkClosedMs = 55;
    }
    else if (roll < 75)
    {
        // Normal blink
        blinkHalfMs = 70;
        blinkClosedMs = 100;
    }
    else
    {
        // Slow, relaxed blink
        blinkHalfMs = 120;
        blinkClosedMs = 180;
    }
}

void startHeartAnimation(Display& display, unsigned long now)
{
    heartAnimation = HeartAnimation::Heart1A;
    heartFrameStartedMs = now;
    display.showFace(Face::Heart1);
}

bool updateHeartAnimation(Display& display, unsigned long now)
{
    if (heartAnimation == HeartAnimation::None)
    {
        return false;
    }

    const unsigned long elapsed = now - heartFrameStartedMs;

    switch (heartAnimation)
    {
        case HeartAnimation::Heart1A:
            if (elapsed >= HEART_SMALL_MS)
            {
                heartAnimation = HeartAnimation::Heart2A;
                heartFrameStartedMs = now;
                display.showFace(Face::Heart2);
            }
            break;

        case HeartAnimation::Heart2A:
            if (elapsed >= HEART_BIG_MS)
            {
                heartAnimation = HeartAnimation::Heart1B;
                heartFrameStartedMs = now;
                display.showFace(Face::Heart1);
            }
            break;

        case HeartAnimation::Heart1B:
            if (elapsed >= HEART_SMALL_MS)
            {
                heartAnimation = HeartAnimation::Heart2B;
                heartFrameStartedMs = now;
                display.showFace(Face::Heart2);
            }
            break;

        case HeartAnimation::Heart2B:
            if (elapsed >= HEART_BIG_MS)
            {
                heartAnimation = HeartAnimation::None;
                display.showFace(Face::Normal);
            }
            break;

        case HeartAnimation::None:
        default:
            break;
    }

    return heartAnimation != HeartAnimation::None;
}
}

void Application::begin()
{
    Serial.begin(115200);

    _display.begin();
    _touch.begin();
    _database.begin();
    _partner.begin();

    _display.showBoot();
    delay(BOOT_TIME_MS);

    const unsigned long now = millis();
    _display.showFace(Face::Normal);
    _lastInteractionMs = now;
    scheduleNextBlink(now);
}

void Application::update()
{
    const unsigned long now = millis();
    const TouchEvent event = _touch.update();

    // Partner heart link: ESP-NOW runs directly between the two devices.
    _partner.update();

    if (_partner.takeIncomingHeart())
    {
        // Make the incoming heart visible immediately, even if this device
        // was sleeping or showing another mode.
        if (_mode != Mode::Home)
        {
            returnHome(false);
        }
        else
        {
            _homeAnimation = HomeAnimation::Normal;
            _sleepFrame = 0;
        }

        _lastInteractionMs = now;
        startHeartAnimation(_display, now);
        Serial.println("[PartnerLink] Showing partner heart <3");
    }

    // Heart animation owns the Home screen until both beats finish.
    if (_mode == Mode::Home && heartAnimation != HeartAnimation::None)
    {
        _lastInteractionMs = now;

        if (!updateHeartAnimation(_display, now))
        {
            scheduleNextBlink(now);
        }

        return;
    }

    if (event != TouchEvent::None)
    {
        _lastInteractionMs = now;

        if (_mode == Mode::Home && _homeAnimation != HomeAnimation::Normal)
        {
            wakeHome(now);
            return;
        }

        if (_mode == Mode::Celebration)
        {
            returnHome();
            return;
        }

        switch (event)
        {
            case TouchEvent::LongPress:
                if (_mode == Mode::Home)
                {
                    enterReview();
                }
                else if (_mode == Mode::Review)
                {
                    returnHome();
                }
                break;

            case TouchEvent::SingleTap:
                if (_mode == Mode::Review)
                {
                    nextPage();
                }
                break;

            case TouchEvent::DoubleTap:
                if (_mode == Mode::Home)
                {
                    startHeartAnimation(_display, now);
                    _partner.sendHeart();
                }
                else if (_mode == Mode::Review)
                {
                    nextRandomCard();
                }
                break;

            case TouchEvent::None:
            default:
                break;
        }
    }

    if (_mode == Mode::Home)
    {
        updateHome(now);
    }
    else if (_mode == Mode::Celebration)
    {
        updateCelebration(now);
    }
}

void Application::enterReview()
{
    _mode = Mode::Review;
    _cardIndex = _database.randomIndex();
    _pageIndex = 0;
    renderReview();
}

void Application::returnHome(bool resetIdleTimer)
{
    const unsigned long now = millis();

    _mode = Mode::Home;
    _homeAnimation = HomeAnimation::Normal;
    _sleepFrame = 0;
    heartAnimation = HeartAnimation::None;
    _display.showFace(Face::Normal);

    if (resetIdleTimer)
    {
        _lastInteractionMs = now;
    }

    scheduleNextBlink(now);
}

void Application::nextPage()
{
    const HanziCard& card = _database.card(_cardIndex);
    const uint16_t pageCount = 3 + card.wordCount;

    if (_pageIndex + 1 >= pageCount)
    {
        startCelebration();
        return;
    }

    ++_pageIndex;
    renderReview();
}

void Application::nextRandomCard()
{
    _cardIndex = _database.randomIndex(_cardIndex);
    _pageIndex = 0;
    renderReview();
}

void Application::startCelebration()
{
    _mode = Mode::Celebration;
    _celebrationFrame = CelebrationFrame::HappyStart;
    _animationStartedMs = millis();
    _display.showFace(Face::Happy);
}

void Application::renderReview()
{
    const HanziCard& card = _database.card(_cardIndex);

    // Page 0: the character itself, with its HSK level in the corner.
    if (_pageIndex == 0)
    {
        char badge[8];
        snprintf(badge, sizeof(badge), "HSK%u", card.hsk);
        _display.showHanzi(card.bitmap, card.width, card.height, badge);
        return;
    }

    // Page 1: readings in pinyin, drawn with Unifont so tone marks line up.
    if (_pageIndex == 1)
    {
        _display.showTextPage("PINYIN", card.pinyin, "", "", 0b001);
        return;
    }

    // Page 2: meaning of the character on its own; it can use all 3 rows.
    if (_pageIndex == 2)
    {
        _display.showTextPage("MEANING", card.meaning);
        return;
    }

    // Pages 3+: every HSK word that uses this character.
    const uint8_t wordIndex = _pageIndex - 3;
    const VocabWord& word = card.words[wordIndex];

    char title[24];
    snprintf(
        title,
        sizeof(title),
        "WORD %u/%u  HSK%u",
        wordIndex + 1,
        card.wordCount,
        word.hsk
    );

    // Keep hanzi and pinyin on one row when they fit; otherwise give the
    // pinyin its own row so it is never split between syllables.
    char wordAndPinyin[128];
    snprintf(wordAndPinyin, sizeof(wordAndPinyin), "%s %s", word.word, word.pinyin);

    if (ChineseFont::measureUTF8(wordAndPinyin, LatinStyle::Unifont) <= Display::TEXT_WIDTH)
    {
        _display.showTextPage(title, wordAndPinyin, word.meaning, "", 0b001);
    }
    else
    {
        _display.showTextPage(title, word.word, word.pinyin, word.meaning, 0b011);
    }
}

void Application::updateHome(unsigned long now)
{
    switch (_homeAnimation)
    {
        case HomeAnimation::BlinkHalfDown:
            if (now - _animationStartedMs >= blinkHalfMs)
            {
                _homeAnimation = HomeAnimation::BlinkClosed;
                _animationStartedMs = now;
                _display.showFace(Face::Closed);
            }
            return;

        case HomeAnimation::BlinkClosed:
            if (now - _animationStartedMs >= blinkClosedMs)
            {
                _homeAnimation = HomeAnimation::BlinkHalfUp;
                _animationStartedMs = now;
                _display.showFace(Face::Half);
            }
            return;

        case HomeAnimation::BlinkHalfUp:
            if (now - _animationStartedMs >= blinkHalfMs)
            {
                _homeAnimation = HomeAnimation::Normal;
                _display.showFace(Face::Normal);
                scheduleNextBlink(now);
            }
            return;

        case HomeAnimation::Sleepy1:
            if (now - _animationStartedMs >= SLEEPY_FRAME1_MS)
            {
                _homeAnimation = HomeAnimation::Sleepy2;
                _animationStartedMs = now;
                _display.showFace(Face::Sleepy2);
            }
            return;

        case HomeAnimation::Sleepy2:
            if (now - _animationStartedMs >= SLEEPY_FRAME2_MS)
            {
                _homeAnimation = HomeAnimation::Sleeping;
                _sleepFrame = 0;
                _animationStartedMs = now;
                _display.showSleepingFrame(_sleepFrame);
            }
            return;

        case HomeAnimation::Sleeping:
            if (now - _animationStartedMs >= SLEEP_Z_SLOW_MS)
            {
                _animationStartedMs = now;
                _sleepFrame = (_sleepFrame + 1) % 10;
                _display.showSleepingFrame(_sleepFrame);
            }
            return;

        case HomeAnimation::Normal:
        default:
            break;
    }

    if (now - _lastInteractionMs >= IDLE_TO_SLEEP_MS)
    {
        beginSleep(now);
        return;
    }

    if (static_cast<long>(now - _nextBlinkMs) >= 0)
    {
        beginBlink(now);
    }
}

void Application::updateCelebration(unsigned long now)
{
    const unsigned long elapsed = now - _animationStartedMs;

    switch (_celebrationFrame)
    {
        case CelebrationFrame::HappyStart:
            if (elapsed >= CELEBRATION_HAPPY_START_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire1;
                _animationStartedMs = now;
                _display.showFace(Face::Fire1);
            }
            break;

        case CelebrationFrame::Fire1:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire2;
                _animationStartedMs = now;
                _display.showFace(Face::Fire2);
            }
            break;

        case CelebrationFrame::Fire2:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire1b;
                _animationStartedMs = now;
                _display.showFace(Face::Fire1);
            }
            break;

        case CelebrationFrame::Fire1b:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire2b;
                _animationStartedMs = now;
                _display.showFace(Face::Fire2);
            }
            break;

        case CelebrationFrame::Fire2b:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire1c;
                _animationStartedMs = now;
                _display.showFace(Face::Fire1);
            }
            break;

        case CelebrationFrame::Fire1c:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::Fire2c;
                _animationStartedMs = now;
                _display.showFace(Face::Fire2);
            }
            break;

        case CelebrationFrame::Fire2c:
            if (elapsed >= CELEBRATION_FIRE_FRAME_MS)
            {
                _celebrationFrame = CelebrationFrame::HappyEnd;
                _animationStartedMs = now;
                _display.showFace(Face::Happy);
            }
            break;

        case CelebrationFrame::HappyEnd:
            if (elapsed >= CELEBRATION_HAPPY_END_MS)
            {
                returnHome();
            }
            break;
    }
}

void Application::beginBlink(unsigned long now)
{
    chooseBlinkTiming();

    _homeAnimation = HomeAnimation::BlinkHalfDown;
    _animationStartedMs = now;
    _display.showFace(Face::Half);
}

void Application::beginSleep(unsigned long now)
{
    _homeAnimation = HomeAnimation::Sleepy1;
    _sleepFrame = 0;
    _animationStartedMs = now;
    _display.showFace(Face::Sleepy1);
}

void Application::scheduleNextBlink(unsigned long now)
{
    _nextBlinkMs = now + random(BLINK_MIN_INTERVAL_MS, BLINK_MAX_INTERVAL_MS + 1);
}

void Application::wakeHome(unsigned long now)
{
    heartAnimation = HeartAnimation::None;
    _homeAnimation = HomeAnimation::Normal;
    _sleepFrame = 0;
    _lastInteractionMs = now;
    _display.showFace(Face::Normal);
    scheduleNextBlink(now);
}
