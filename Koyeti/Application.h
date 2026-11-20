#ifndef APPLICATION_H
#define APPLICATION_H

#include "Display.h"
#include "Touch.h"
#include "Database.h"
#include "PartnerLink.h"

class Application
{
public:
    void begin();
    void update();

private:
    enum class Mode : uint8_t
    {
        Home,
        Review,
        Celebration
    };

    enum class HomeAnimation : uint8_t
    {
        Normal,
        BlinkHalfDown,
        BlinkClosed,
        BlinkHalfUp,
        Sleepy1,
        Sleepy2,
        Sleeping
    };

    enum class CelebrationFrame : uint8_t
    {
        HappyStart,
        Fire1,
        Fire2,
        Fire1b,
        Fire2b,
        Fire1c,
        Fire2c,
        HappyEnd
    };

    void enterReview();
    void returnHome(bool resetIdleTimer = true);
    void nextPage();
    void nextRandomCard();
    void startCelebration();
    void renderReview();

    void updateHome(unsigned long now);
    void updateCelebration(unsigned long now);
    void beginBlink(unsigned long now);
    void beginSleep(unsigned long now);
    void scheduleNextBlink(unsigned long now);
    void wakeHome(unsigned long now);

    Display _display;
    Touch _touch;
    Database _database;
    PartnerLink _partner;

    Mode _mode = Mode::Home;
    HomeAnimation _homeAnimation = HomeAnimation::Normal;
    CelebrationFrame _celebrationFrame = CelebrationFrame::HappyStart;

    uint16_t _cardIndex = 0;
    uint8_t _pageIndex = 0;
    uint8_t _sleepFrame = 0;

    unsigned long _animationStartedMs = 0;
    unsigned long _nextBlinkMs = 0;
    unsigned long _lastInteractionMs = 0;
};

#endif
