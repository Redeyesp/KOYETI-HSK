// Generated automatically by scripts/build_firmware_database.py. Do not edit.
// Meaning language: en
#include "Database.h"
#include <Preferences.h>
#include <esp_system.h>

#include "generated/hanzi/hanzi_7231.h"
#include "generated/hanzi/hanzi_516B.h"
#include "generated/hanzi/hanzi_7238.h"
#include "generated/hanzi/hanzi_676F.h"
#include "generated/hanzi/hanzi_5B50.h"
#include "generated/hanzi/hanzi_5317.h"
#include "generated/hanzi/hanzi_4EAC.h"
#include "generated/hanzi/hanzi_672C.h"
#include "generated/hanzi/hanzi_4E0D.h"
#include "generated/hanzi/hanzi_5BA2.h"
#include "generated/hanzi/hanzi_6C14.h"
#include "generated/hanzi/hanzi_83DC.h"
#include "generated/hanzi/hanzi_8336.h"
#include "generated/hanzi/hanzi_5403.h"
#include "generated/hanzi/hanzi_51FA.h"
#include "generated/hanzi/hanzi_79DF.h"
#include "generated/hanzi/hanzi_8F66.h"
#include "generated/hanzi/hanzi_6253.h"
#include "generated/hanzi/hanzi_7535.h"
#include "generated/hanzi/hanzi_8BDD.h"
#include "generated/hanzi/hanzi_5927.h"
#include "generated/hanzi/hanzi_7684.h"
#include "generated/hanzi/hanzi_70B9.h"
#include "generated/hanzi/hanzi_8111.h"
#include "generated/hanzi/hanzi_89C6.h"
#include "generated/hanzi/hanzi_5F71.h"
#include "generated/hanzi/hanzi_4E1C.h"
#include "generated/hanzi/hanzi_897F.h"
#include "generated/hanzi/hanzi_90FD.h"
#include "generated/hanzi/hanzi_8BFB.h"
#include "generated/hanzi/hanzi_5BF9.h"
#include "generated/hanzi/hanzi_8D77.h"
#include "generated/hanzi/hanzi_591A.h"
#include "generated/hanzi/hanzi_5C11.h"
#include "generated/hanzi/hanzi_513F.h"
#include "generated/hanzi/hanzi_4E8C.h"
#include "generated/hanzi/hanzi_996D.h"
#include "generated/hanzi/hanzi_5E97.h"
#include "generated/hanzi/hanzi_98DE.h"
#include "generated/hanzi/hanzi_673A.h"
#include "generated/hanzi/hanzi_5206.h"
#include "generated/hanzi/hanzi_949F.h"
#include "generated/hanzi/hanzi_9AD8.h"
#include "generated/hanzi/hanzi_5174.h"
#include "generated/hanzi/hanzi_4E2A.h"
#include "generated/hanzi/hanzi_5DE5.h"
#include "generated/hanzi/hanzi_4F5C.h"
#include "generated/hanzi/hanzi_72D7.h"
#include "generated/hanzi/hanzi_6C49.h"
#include "generated/hanzi/hanzi_8BED.h"
#include "generated/hanzi/hanzi_597D.h"
#include "generated/hanzi/hanzi_53F7.h"
#include "generated/hanzi/hanzi_559D.h"
#include "generated/hanzi/hanzi_548C.h"
#include "generated/hanzi/hanzi_5F88.h"
#include "generated/hanzi/hanzi_540E.h"
#include "generated/hanzi/hanzi_9762.h"
#include "generated/hanzi/hanzi_56DE.h"
#include "generated/hanzi/hanzi_4F1A.h"
#include "generated/hanzi/hanzi_51E0.h"
#include "generated/hanzi/hanzi_5BB6.h"
#include "generated/hanzi/hanzi_53EB.h"
#include "generated/hanzi/hanzi_4ECA.h"
#include "generated/hanzi/hanzi_5929.h"
#include "generated/hanzi/hanzi_4E5D.h"
#include "generated/hanzi/hanzi_5F00.h"
#include "generated/hanzi/hanzi_770B.h"
#include "generated/hanzi/hanzi_89C1.h"
#include "generated/hanzi/hanzi_5757.h"
#include "generated/hanzi/hanzi_6765.h"
#include "generated/hanzi/hanzi_8001.h"
#include "generated/hanzi/hanzi_5E08.h"
#include "generated/hanzi/hanzi_4E86.h"
#include "generated/hanzi/hanzi_51B7.h"
#include "generated/hanzi/hanzi_91CC.h"
#include "generated/hanzi/hanzi_516D.h"
#include "generated/hanzi/hanzi_5988.h"
#include "generated/hanzi/hanzi_5417.h"
#include "generated/hanzi/hanzi_4E70.h"
#include "generated/hanzi/hanzi_732B.h"
#include "generated/hanzi/hanzi_6CA1.h"
#include "generated/hanzi/hanzi_5173.h"
#include "generated/hanzi/hanzi_7CFB.h"
#include "generated/hanzi/hanzi_6709.h"
#include "generated/hanzi/hanzi_7C73.h"
#include "generated/hanzi/hanzi_660E.h"
#include "generated/hanzi/hanzi_540D.h"
#include "generated/hanzi/hanzi_5B57.h"
#include "generated/hanzi/hanzi_54EA.h"
#include "generated/hanzi/hanzi_90A3.h"
#include "generated/hanzi/hanzi_5462.h"
#include "generated/hanzi/hanzi_80FD.h"
#include "generated/hanzi/hanzi_4F60.h"
#include "generated/hanzi/hanzi_5E74.h"
#include "generated/hanzi/hanzi_5973.h"
#include "generated/hanzi/hanzi_670B.h"
#include "generated/hanzi/hanzi_53CB.h"
#include "generated/hanzi/hanzi_6F02.h"
#include "generated/hanzi/hanzi_4EAE.h"
#include "generated/hanzi/hanzi_82F9.h"
#include "generated/hanzi/hanzi_679C.h"
#include "generated/hanzi/hanzi_4E03.h"
#include "generated/hanzi/hanzi_94B1.h"
#include "generated/hanzi/hanzi_524D.h"
#include "generated/hanzi/hanzi_8BF7.h"
#include "generated/hanzi/hanzi_53BB.h"
#include "generated/hanzi/hanzi_70ED.h"
#include "generated/hanzi/hanzi_4EBA.h"
#include "generated/hanzi/hanzi_8BA4.h"
#include "generated/hanzi/hanzi_8BC6.h"
#include "generated/hanzi/hanzi_4E09.h"
#include "generated/hanzi/hanzi_5546.h"
#include "generated/hanzi/hanzi_4E0A.h"
#include "generated/hanzi/hanzi_5348.h"
#include "generated/hanzi/hanzi_8C01.h"
#include "generated/hanzi/hanzi_4EC0.h"
#include "generated/hanzi/hanzi_4E48.h"
#include "generated/hanzi/hanzi_5341.h"
#include "generated/hanzi/hanzi_65F6.h"
#include "generated/hanzi/hanzi_5019.h"
#include "generated/hanzi/hanzi_662F.h"
#include "generated/hanzi/hanzi_4E66.h"
#include "generated/hanzi/hanzi_6C34.h"
#include "generated/hanzi/hanzi_7761.h"
#include "generated/hanzi/hanzi_89C9.h"
#include "generated/hanzi/hanzi_8BF4.h"
#include "generated/hanzi/hanzi_56DB.h"
#include "generated/hanzi/hanzi_5C81.h"
#include "generated/hanzi/hanzi_4ED6.h"
#include "generated/hanzi/hanzi_5979.h"
#include "generated/hanzi/hanzi_592A.h"
#include "generated/hanzi/hanzi_542C.h"
#include "generated/hanzi/hanzi_540C.h"
#include "generated/hanzi/hanzi_5B66.h"
#include "generated/hanzi/hanzi_5582.h"
#include "generated/hanzi/hanzi_6211.h"
#include "generated/hanzi/hanzi_4EEC.h"
#include "generated/hanzi/hanzi_4E94.h"
#include "generated/hanzi/hanzi_559C.h"
#include "generated/hanzi/hanzi_6B22.h"
#include "generated/hanzi/hanzi_4E0B.h"
#include "generated/hanzi/hanzi_96E8.h"
#include "generated/hanzi/hanzi_5148.h"
#include "generated/hanzi/hanzi_751F.h"
#include "generated/hanzi/hanzi_73B0.h"
#include "generated/hanzi/hanzi_5728.h"
#include "generated/hanzi/hanzi_60F3.h"
#include "generated/hanzi/hanzi_5C0F.h"
#include "generated/hanzi/hanzi_59D0.h"
#include "generated/hanzi/hanzi_4E9B.h"
#include "generated/hanzi/hanzi_5199.h"
#include "generated/hanzi/hanzi_8C22.h"
#include "generated/hanzi/hanzi_661F.h"
#include "generated/hanzi/hanzi_671F.h"
#include "generated/hanzi/hanzi_4E60.h"
#include "generated/hanzi/hanzi_6821.h"
#include "generated/hanzi/hanzi_4E00.h"
#include "generated/hanzi/hanzi_8863.h"
#include "generated/hanzi/hanzi_670D.h"
#include "generated/hanzi/hanzi_533B.h"
#include "generated/hanzi/hanzi_9662.h"
#include "generated/hanzi/hanzi_6905.h"
#include "generated/hanzi/hanzi_6708.h"
#include "generated/hanzi/hanzi_518D.h"
#include "generated/hanzi/hanzi_600E.h"
#include "generated/hanzi/hanzi_6837.h"
#include "generated/hanzi/hanzi_8FD9.h"
#include "generated/hanzi/hanzi_4E2D.h"
#include "generated/hanzi/hanzi_56FD.h"
#include "generated/hanzi/hanzi_4F4F.h"
#include "generated/hanzi/hanzi_684C.h"
#include "generated/hanzi/hanzi_6628.h"
#include "generated/hanzi/hanzi_5750.h"
#include "generated/hanzi/hanzi_505A.h"
#include "generated/hanzi/hanzi_5427.h"
#include "generated/hanzi/hanzi_767D.h"
#include "generated/hanzi/hanzi_767E.h"
#include "generated/hanzi/hanzi_5E2E.h"
#include "generated/hanzi/hanzi_52A9.h"
#include "generated/hanzi/hanzi_62A5.h"
#include "generated/hanzi/hanzi_7EB8.h"
#include "generated/hanzi/hanzi_6BD4.h"
#include "generated/hanzi/hanzi_522B.h"
#include "generated/hanzi/hanzi_5BBE.h"
#include "generated/hanzi/hanzi_9986.h"
#include "generated/hanzi/hanzi_957F.h"
#include "generated/hanzi/hanzi_5531.h"
#include "generated/hanzi/hanzi_6B4C.h"
#include "generated/hanzi/hanzi_7A7F.h"
#include "generated/hanzi/hanzi_6B21.h"
#include "generated/hanzi/hanzi_4ECE.h"
#include "generated/hanzi/hanzi_9519.h"
#include "generated/hanzi/hanzi_7BEE.h"
#include "generated/hanzi/hanzi_7403.h"
#include "generated/hanzi/hanzi_5230.h"
#include "generated/hanzi/hanzi_5F97.h"
#include "generated/hanzi/hanzi_7B49.h"
#include "generated/hanzi/hanzi_5F1F.h"
#include "generated/hanzi/hanzi_7B2C.h"
#include "generated/hanzi/hanzi_61C2.h"
#include "generated/hanzi/hanzi_623F.h"
#include "generated/hanzi/hanzi_95F4.h"
#include "generated/hanzi/hanzi_975E.h"
#include "generated/hanzi/hanzi_5E38.h"
#include "generated/hanzi/hanzi_52A1.h"
#include "generated/hanzi/hanzi_5458.h"
#include "generated/hanzi/hanzi_544A.h"
#include "generated/hanzi/hanzi_8BC9.h"
#include "generated/hanzi/hanzi_54E5.h"
#include "generated/hanzi/hanzi_7ED9.h"
#include "generated/hanzi/hanzi_516C.h"
#include "generated/hanzi/hanzi_5171.h"
#include "generated/hanzi/hanzi_6C7D.h"
#include "generated/hanzi/hanzi_53F8.h"
#include "generated/hanzi/hanzi_8D35.h"
#include "generated/hanzi/hanzi_8FC7.h"
#include "generated/hanzi/hanzi_8FD8.h"
#include "generated/hanzi/hanzi_5B69.h"
#include "generated/hanzi/hanzi_9ED1.h"
#include "generated/hanzi/hanzi_7EA2.h"
#include "generated/hanzi/hanzi_706B.h"
#include "generated/hanzi/hanzi_7AD9.h"
#include "generated/hanzi/hanzi_573A.h"
#include "generated/hanzi/hanzi_9E21.h"
#include "generated/hanzi/hanzi_86CB.h"
#include "generated/hanzi/hanzi_4EF6.h"
#include "generated/hanzi/hanzi_6559.h"
#include "generated/hanzi/hanzi_5BA4.h"
#include "generated/hanzi/hanzi_4ECB.h"
#include "generated/hanzi/hanzi_7ECD.h"
#include "generated/hanzi/hanzi_8FD1.h"
#include "generated/hanzi/hanzi_8FDB.h"
#include "generated/hanzi/hanzi_5C31.h"
#include "generated/hanzi/hanzi_5496.h"
#include "generated/hanzi/hanzi_5561.h"
#include "generated/hanzi/hanzi_59CB.h"
#include "generated/hanzi/hanzi_8003.h"
#include "generated/hanzi/hanzi_8BD5.h"
#include "generated/hanzi/hanzi_53EF.h"
#include "generated/hanzi/hanzi_4EE5.h"
#include "generated/hanzi/hanzi_8BFE.h"
#include "generated/hanzi/hanzi_5FEB.h"
#include "generated/hanzi/hanzi_4E50.h"
#include "generated/hanzi/hanzi_7D2F.h"
#include "generated/hanzi/hanzi_79BB.h"
#include "generated/hanzi/hanzi_4E24.h"
#include "generated/hanzi/hanzi_96F6.h"
#include "generated/hanzi/hanzi_8DEF.h"
#include "generated/hanzi/hanzi_65C5.h"
#include "generated/hanzi/hanzi_6E38.h"
#include "generated/hanzi/hanzi_5356.h"
#include "generated/hanzi/hanzi_6162.h"
#include "generated/hanzi/hanzi_5FD9.h"
#include "generated/hanzi/hanzi_6BCF.h"
#include "generated/hanzi/hanzi_59B9.h"
#include "generated/hanzi/hanzi_95E8.h"
#include "generated/hanzi/hanzi_6761.h"
#include "generated/hanzi/hanzi_7537.h"
#include "generated/hanzi/hanzi_60A8.h"
#include "generated/hanzi/hanzi_725B.h"
#include "generated/hanzi/hanzi_5976.h"
#include "generated/hanzi/hanzi_65C1.h"
#include "generated/hanzi/hanzi_8FB9.h"
#include "generated/hanzi/hanzi_8DD1.h"
#include "generated/hanzi/hanzi_6B65.h"
#include "generated/hanzi/hanzi_4FBF.h"
#include "generated/hanzi/hanzi_5B9C.h"
#include "generated/hanzi/hanzi_7968.h"
#include "generated/hanzi/hanzi_59BB.h"
#include "generated/hanzi/hanzi_5E8A.h"
#include "generated/hanzi/hanzi_5343.h"
#include "generated/hanzi/hanzi_94C5.h"
#include "generated/hanzi/hanzi_7B14.h"
#include "generated/hanzi/hanzi_6674.h"
#include "generated/hanzi/hanzi_8BA9.h"
#include "generated/hanzi/hanzi_65E5.h"
#include "generated/hanzi/hanzi_73ED.h"
#include "generated/hanzi/hanzi_8EAB.h"
#include "generated/hanzi/hanzi_4F53.h"
#include "generated/hanzi/hanzi_75C5.h"
#include "generated/hanzi/hanzi_4E8B.h"
#include "generated/hanzi/hanzi_60C5.h"
#include "generated/hanzi/hanzi_624B.h"
#include "generated/hanzi/hanzi_8868.h"
#include "generated/hanzi/hanzi_9001.h"
#include "generated/hanzi/hanzi_867D.h"
#include "generated/hanzi/hanzi_7136.h"
#include "generated/hanzi/hanzi_4F46.h"
#include "generated/hanzi/hanzi_5B83.h"
#include "generated/hanzi/hanzi_8E22.h"
#include "generated/hanzi/hanzi_9898.h"
#include "generated/hanzi/hanzi_8DF3.h"
#include "generated/hanzi/hanzi_821E.h"
#include "generated/hanzi/hanzi_5916.h"
#include "generated/hanzi/hanzi_5B8C.h"
#include "generated/hanzi/hanzi_73A9.h"
#include "generated/hanzi/hanzi_665A.h"
#include "generated/hanzi/hanzi_5F80.h"
#include "generated/hanzi/hanzi_4E3A.h"
#include "generated/hanzi/hanzi_95EE.h"
#include "generated/hanzi/hanzi_74DC.h"
#include "generated/hanzi/hanzi_5E0C.h"
#include "generated/hanzi/hanzi_671B.h"
#include "generated/hanzi/hanzi_6D17.h"
#include "generated/hanzi/hanzi_7B11.h"
#include "generated/hanzi/hanzi_65B0.h"
#include "generated/hanzi/hanzi_59D3.h"
#include "generated/hanzi/hanzi_4F11.h"
#include "generated/hanzi/hanzi_606F.h"
#include "generated/hanzi/hanzi_96EA.h"
#include "generated/hanzi/hanzi_989C.h"
#include "generated/hanzi/hanzi_8272.h"
#include "generated/hanzi/hanzi_773C.h"
#include "generated/hanzi/hanzi_775B.h"
#include "generated/hanzi/hanzi_7F8A.h"
#include "generated/hanzi/hanzi_8089.h"
#include "generated/hanzi/hanzi_8981.h"
#include "generated/hanzi/hanzi_836F.h"
#include "generated/hanzi/hanzi_4E5F.h"
#include "generated/hanzi/hanzi_5DF2.h"
#include "generated/hanzi/hanzi_7ECF.h"
#include "generated/hanzi/hanzi_610F.h"
#include "generated/hanzi/hanzi_601D.h"
#include "generated/hanzi/hanzi_9634.h"
#include "generated/hanzi/hanzi_56E0.h"
#include "generated/hanzi/hanzi_6240.h"
#include "generated/hanzi/hanzi_6CF3.h"
#include "generated/hanzi/hanzi_53F3.h"
#include "generated/hanzi/hanzi_9C7C.h"
#include "generated/hanzi/hanzi_8FDC.h"
#include "generated/hanzi/hanzi_8FD0.h"
#include "generated/hanzi/hanzi_52A8.h"
#include "generated/hanzi/hanzi_65E9.h"
#include "generated/hanzi/hanzi_4E08.h"
#include "generated/hanzi/hanzi_592B.h"
#include "generated/hanzi/hanzi_627E.h"
#include "generated/hanzi/hanzi_7740.h"
#include "generated/hanzi/hanzi_771F.h"
#include "generated/hanzi/hanzi_6B63.h"
#include "generated/hanzi/hanzi_53EA.h"
#include "generated/hanzi/hanzi_77E5.h"
#include "generated/hanzi/hanzi_9053.h"
#include "generated/hanzi/hanzi_51C6.h"
#include "generated/hanzi/hanzi_5907.h"
#include "generated/hanzi/hanzi_8D70.h"
#include "generated/hanzi/hanzi_6700.h"
#include "generated/hanzi/hanzi_5DE6.h"

namespace
{
// 爱
const VocabWord WORDS_U7231[] =
{
    {"爱", "ài", "to love", 1},
};

// 八
const VocabWord WORDS_U516B[] =
{
    {"八", "bā", "eight", 1},
};

// 爸
const VocabWord WORDS_U7238[] =
{
    {"爸爸", "bàba", "dad", 1},
};

// 杯
const VocabWord WORDS_U676F[] =
{
    {"杯子", "bēizi", "cup; glass", 1},
};

// 子
const VocabWord WORDS_U5B50[] =
{
    {"杯子", "bēizi", "cup; glass", 1},
    {"儿子", "érzi", "son", 1},
    {"椅子", "yǐzi", "chair", 1},
    {"桌子", "zhuōzi", "table; desk", 1},
    {"孩子", "háizi", "child", 2},
    {"妻子", "qīzi", "wife", 2},
};

// 北
const VocabWord WORDS_U5317[] =
{
    {"北京", "Běijīng", "Beijing", 1},
};

// 京
const VocabWord WORDS_U4EAC[] =
{
    {"北京", "Běijīng", "Beijing", 1},
};

// 本
const VocabWord WORDS_U672C[] =
{
    {"本", "běn", "measure word for books", 1},
};

// 不
const VocabWord WORDS_U4E0D[] =
{
    {"不", "bù", "not; no", 1},
    {"不客气", "bú kèqi", "you're welcome", 1},
    {"对不起", "duìbuqǐ", "sorry", 1},
};

// 客
const VocabWord WORDS_U5BA2[] =
{
    {"不客气", "bú kèqi", "you're welcome", 1},
};

// 气
const VocabWord WORDS_U6C14[] =
{
    {"不客气", "bú kèqi", "you're welcome", 1},
    {"天气", "tiānqì", "weather", 1},
};

// 菜
const VocabWord WORDS_U83DC[] =
{
    {"菜", "cài", "dish; vegetable", 1},
};

// 茶
const VocabWord WORDS_U8336[] =
{
    {"茶", "chá", "tea", 1},
};

// 吃
const VocabWord WORDS_U5403[] =
{
    {"吃", "chī", "to eat", 1},
    {"好吃", "hǎochī", "tasty", 2},
};

// 出
const VocabWord WORDS_U51FA[] =
{
    {"出", "chū", "to go out", 2},
    {"出租车", "chūzūchē", "taxi", 1},
};

// 租
const VocabWord WORDS_U79DF[] =
{
    {"出租车", "chūzūchē", "taxi", 1},
};

// 车
const VocabWord WORDS_U8F66[] =
{
    {"出租车", "chūzūchē", "taxi", 1},
    {"公共汽车", "gōnggòng qìchē", "bus", 2},
    {"火车站", "huǒchēzhàn", "train station", 2},
};

// 打
const VocabWord WORDS_U6253[] =
{
    {"打电话", "dǎ diànhuà", "to make a phone call", 1},
    {"打篮球", "dǎ lánqiú", "to play basketball", 2},
};

// 电
const VocabWord WORDS_U7535[] =
{
    {"打电话", "dǎ diànhuà", "to make a phone call", 1},
    {"电脑", "diànnǎo", "computer", 1},
    {"电视", "diànshì", "television", 1},
    {"电影", "diànyǐng", "movie", 1},
};

// 话
const VocabWord WORDS_U8BDD[] =
{
    {"打电话", "dǎ diànhuà", "to make a phone call", 1},
    {"说话", "shuōhuà", "to talk", 2},
};

// 大
const VocabWord WORDS_U5927[] =
{
    {"大", "dà", "big", 1},
    {"大家", "dàjiā", "everyone", 2},
};

// 的
const VocabWord WORDS_U7684[] =
{
    {"的", "de", "possessive particle", 1},
};

// 点
const VocabWord WORDS_U70B9[] =
{
    {"点", "diǎn", "o'clock; dot", 1},
    {"一点儿", "yìdiǎnr", "a little", 1},
};

// 脑
const VocabWord WORDS_U8111[] =
{
    {"电脑", "diànnǎo", "computer", 1},
};

// 视
const VocabWord WORDS_U89C6[] =
{
    {"电视", "diànshì", "television", 1},
};

// 影
const VocabWord WORDS_U5F71[] =
{
    {"电影", "diànyǐng", "movie", 1},
};

// 东
const VocabWord WORDS_U4E1C[] =
{
    {"东西", "dōngxi", "thing; stuff", 1},
};

// 西
const VocabWord WORDS_U897F[] =
{
    {"东西", "dōngxi", "thing; stuff", 1},
    {"西瓜", "xīguā", "watermelon", 2},
};

// 都
const VocabWord WORDS_U90FD[] =
{
    {"都", "dōu", "all; both", 1},
};

// 读
const VocabWord WORDS_U8BFB[] =
{
    {"读", "dú", "to read (aloud)", 1},
};

// 对
const VocabWord WORDS_U5BF9[] =
{
    {"对", "duì", "correct; to; toward", 2},
    {"对不起", "duìbuqǐ", "sorry", 1},
};

// 起
const VocabWord WORDS_U8D77[] =
{
    {"对不起", "duìbuqǐ", "sorry", 1},
    {"起床", "qǐchuáng", "to get up", 2},
    {"一起", "yìqǐ", "together", 2},
};

// 多
const VocabWord WORDS_U591A[] =
{
    {"多", "duō", "many; much", 1},
    {"多少", "duōshao", "how many; how much", 1},
};

// 少
const VocabWord WORDS_U5C11[] =
{
    {"少", "shǎo", "few; little", 1},
    {"多少", "duōshao", "how many; how much", 1},
};

// 儿
const VocabWord WORDS_U513F[] =
{
    {"儿子", "érzi", "son", 1},
    {"哪儿", "nǎr", "where", 1},
    {"女儿", "nǚ'ér", "daughter", 1},
    {"一点儿", "yìdiǎnr", "a little", 1},
};

// 二
const VocabWord WORDS_U4E8C[] =
{
    {"二", "èr", "two", 1},
};

// 饭
const VocabWord WORDS_U996D[] =
{
    {"饭店", "fàndiàn", "restaurant; hotel", 1},
    {"米饭", "mǐfàn", "cooked rice", 1},
};

// 店
const VocabWord WORDS_U5E97[] =
{
    {"饭店", "fàndiàn", "restaurant; hotel", 1},
    {"商店", "shāngdiàn", "shop; store", 1},
};

// 飞
const VocabWord WORDS_U98DE[] =
{
    {"飞机", "fēijī", "airplane", 1},
};

// 机
const VocabWord WORDS_U673A[] =
{
    {"飞机", "fēijī", "airplane", 1},
    {"机场", "jīchǎng", "airport", 2},
    {"手机", "shǒujī", "mobile phone", 2},
};

// 分
const VocabWord WORDS_U5206[] =
{
    {"分钟", "fēnzhōng", "minute", 1},
};

// 钟
const VocabWord WORDS_U949F[] =
{
    {"分钟", "fēnzhōng", "minute", 1},
};

// 高
const VocabWord WORDS_U9AD8[] =
{
    {"高", "gāo", "tall; high", 2},
    {"高兴", "gāoxìng", "happy; glad", 1},
};

// 兴
const VocabWord WORDS_U5174[] =
{
    {"高兴", "gāoxìng", "happy; glad", 1},
};

// 个
const VocabWord WORDS_U4E2A[] =
{
    {"个", "gè", "general measure word", 1},
};

// 工
const VocabWord WORDS_U5DE5[] =
{
    {"工作", "gōngzuò", "to work; job", 1},
};

// 作
const VocabWord WORDS_U4F5C[] =
{
    {"工作", "gōngzuò", "to work; job", 1},
};

// 狗
const VocabWord WORDS_U72D7[] =
{
    {"狗", "gǒu", "dog", 1},
};

// 汉
const VocabWord WORDS_U6C49[] =
{
    {"汉语", "Hànyǔ", "Chinese language", 1},
};

// 语
const VocabWord WORDS_U8BED[] =
{
    {"汉语", "Hànyǔ", "Chinese language", 1},
};

// 好
const VocabWord WORDS_U597D[] =
{
    {"好", "hǎo", "good; well", 1},
    {"好吃", "hǎochī", "tasty", 2},
};

// 号
const VocabWord WORDS_U53F7[] =
{
    {"号", "hào", "day of month; number", 1},
};

// 喝
const VocabWord WORDS_U559D[] =
{
    {"喝", "hē", "to drink", 1},
};

// 和
const VocabWord WORDS_U548C[] =
{
    {"和", "hé", "and; with", 1},
};

// 很
const VocabWord WORDS_U5F88[] =
{
    {"很", "hěn", "very", 1},
};

// 后
const VocabWord WORDS_U540E[] =
{
    {"后面", "hòumian", "behind; at the back", 1},
};

// 面
const VocabWord WORDS_U9762[] =
{
    {"后面", "hòumian", "behind; at the back", 1},
    {"前面", "qiánmian", "in front; ahead", 1},
    {"面条", "miàntiáo", "noodles", 2},
};

// 回
const VocabWord WORDS_U56DE[] =
{
    {"回", "huí", "to return", 1},
};

// 会
const VocabWord WORDS_U4F1A[] =
{
    {"会", "huì", "can; know how to", 1},
};

// 几
const VocabWord WORDS_U51E0[] =
{
    {"几", "jǐ", "how many; a few", 1},
};

// 家
const VocabWord WORDS_U5BB6[] =
{
    {"家", "jiā", "home; family", 1},
    {"大家", "dàjiā", "everyone", 2},
};

// 叫
const VocabWord WORDS_U53EB[] =
{
    {"叫", "jiào", "to be called; to call", 1},
};

// 今
const VocabWord WORDS_U4ECA[] =
{
    {"今天", "jīntiān", "today", 1},
};

// 天
const VocabWord WORDS_U5929[] =
{
    {"今天", "jīntiān", "today", 1},
    {"明天", "míngtiān", "tomorrow", 1},
    {"天气", "tiānqì", "weather", 1},
    {"昨天", "zuótiān", "yesterday", 1},
};

// 九
const VocabWord WORDS_U4E5D[] =
{
    {"九", "jiǔ", "nine", 1},
};

// 开
const VocabWord WORDS_U5F00[] =
{
    {"开", "kāi", "to open; to drive", 1},
    {"开始", "kāishǐ", "to begin", 2},
};

// 看
const VocabWord WORDS_U770B[] =
{
    {"看", "kàn", "to look; to watch", 1},
    {"看见", "kànjiàn", "to see", 1},
};

// 见
const VocabWord WORDS_U89C1[] =
{
    {"看见", "kànjiàn", "to see", 1},
    {"再见", "zàijiàn", "goodbye", 1},
};

// 块
const VocabWord WORDS_U5757[] =
{
    {"块", "kuài", "yuan (money); piece", 1},
};

// 来
const VocabWord WORDS_U6765[] =
{
    {"来", "lái", "to come", 1},
};

// 老
const VocabWord WORDS_U8001[] =
{
    {"老师", "lǎoshī", "teacher", 1},
};

// 师
const VocabWord WORDS_U5E08[] =
{
    {"老师", "lǎoshī", "teacher", 1},
};

// 了
const VocabWord WORDS_U4E86[] =
{
    {"了", "le", "particle: completed action", 1},
};

// 冷
const VocabWord WORDS_U51B7[] =
{
    {"冷", "lěng", "cold", 1},
};

// 里
const VocabWord WORDS_U91CC[] =
{
    {"里", "lǐ", "inside", 1},
};

// 六
const VocabWord WORDS_U516D[] =
{
    {"六", "liù", "six", 1},
};

// 妈
const VocabWord WORDS_U5988[] =
{
    {"妈妈", "māma", "mom", 1},
};

// 吗
const VocabWord WORDS_U5417[] =
{
    {"吗", "ma", "question particle", 1},
};

// 买
const VocabWord WORDS_U4E70[] =
{
    {"买", "mǎi", "to buy", 1},
};

// 猫
const VocabWord WORDS_U732B[] =
{
    {"猫", "māo", "cat", 1},
};

// 没
const VocabWord WORDS_U6CA1[] =
{
    {"没关系", "méi guānxi", "it doesn't matter", 1},
    {"没有", "méiyǒu", "not have; did not", 1},
};

// 关
const VocabWord WORDS_U5173[] =
{
    {"没关系", "méi guānxi", "it doesn't matter", 1},
};

// 系
const VocabWord WORDS_U7CFB[] =
{
    {"没关系", "méi guānxi", "it doesn't matter", 1},
};

// 有
const VocabWord WORDS_U6709[] =
{
    {"有", "yǒu", "to have; there is", 1},
    {"没有", "méiyǒu", "not have; did not", 1},
};

// 米
const VocabWord WORDS_U7C73[] =
{
    {"米饭", "mǐfàn", "cooked rice", 1},
};

// 明
const VocabWord WORDS_U660E[] =
{
    {"明天", "míngtiān", "tomorrow", 1},
};

// 名
const VocabWord WORDS_U540D[] =
{
    {"名字", "míngzi", "name", 1},
};

// 字
const VocabWord WORDS_U5B57[] =
{
    {"字", "zì", "character; word", 1},
    {"名字", "míngzi", "name", 1},
};

// 哪
const VocabWord WORDS_U54EA[] =
{
    {"哪", "nǎ", "which", 1},
    {"哪儿", "nǎr", "where", 1},
};

// 那
const VocabWord WORDS_U90A3[] =
{
    {"那", "nà", "that", 1},
};

// 呢
const VocabWord WORDS_U5462[] =
{
    {"呢", "ne", "particle: and you? / still", 1},
};

// 能
const VocabWord WORDS_U80FD[] =
{
    {"能", "néng", "can; be able to", 1},
    {"可能", "kěnéng", "maybe; possible", 2},
};

// 你
const VocabWord WORDS_U4F60[] =
{
    {"你", "nǐ", "you", 1},
};

// 年
const VocabWord WORDS_U5E74[] =
{
    {"年", "nián", "year", 1},
    {"去年", "qùnián", "last year", 2},
};

// 女
const VocabWord WORDS_U5973[] =
{
    {"女", "nǚ", "female", 2},
    {"女儿", "nǚ'ér", "daughter", 1},
};

// 朋
const VocabWord WORDS_U670B[] =
{
    {"朋友", "péngyou", "friend", 1},
};

// 友
const VocabWord WORDS_U53CB[] =
{
    {"朋友", "péngyou", "friend", 1},
};

// 漂
const VocabWord WORDS_U6F02[] =
{
    {"漂亮", "piàoliang", "pretty; beautiful", 1},
};

// 亮
const VocabWord WORDS_U4EAE[] =
{
    {"漂亮", "piàoliang", "pretty; beautiful", 1},
};

// 苹
const VocabWord WORDS_U82F9[] =
{
    {"苹果", "píngguǒ", "apple", 1},
};

// 果
const VocabWord WORDS_U679C[] =
{
    {"苹果", "píngguǒ", "apple", 1},
    {"水果", "shuǐguǒ", "fruit", 1},
};

// 七
const VocabWord WORDS_U4E03[] =
{
    {"七", "qī", "seven", 1},
};

// 钱
const VocabWord WORDS_U94B1[] =
{
    {"钱", "qián", "money", 1},
};

// 前
const VocabWord WORDS_U524D[] =
{
    {"前面", "qiánmian", "in front; ahead", 1},
};

// 请
const VocabWord WORDS_U8BF7[] =
{
    {"请", "qǐng", "please; to invite", 1},
};

// 去
const VocabWord WORDS_U53BB[] =
{
    {"去", "qù", "to go", 1},
    {"去年", "qùnián", "last year", 2},
};

// 热
const VocabWord WORDS_U70ED[] =
{
    {"热", "rè", "hot", 1},
};

// 人
const VocabWord WORDS_U4EBA[] =
{
    {"人", "rén", "person", 1},
};

// 认
const VocabWord WORDS_U8BA4[] =
{
    {"认识", "rènshi", "to know (someone)", 1},
};

// 识
const VocabWord WORDS_U8BC6[] =
{
    {"认识", "rènshi", "to know (someone)", 1},
};

// 三
const VocabWord WORDS_U4E09[] =
{
    {"三", "sān", "three", 1},
};

// 商
const VocabWord WORDS_U5546[] =
{
    {"商店", "shāngdiàn", "shop; store", 1},
};

// 上
const VocabWord WORDS_U4E0A[] =
{
    {"上", "shàng", "up; on; above", 1},
    {"上午", "shàngwǔ", "morning (before noon)", 1},
    {"上班", "shàngbān", "to go to work", 2},
    {"晚上", "wǎnshang", "evening; night", 2},
    {"早上", "zǎoshang", "early morning", 2},
};

// 午
const VocabWord WORDS_U5348[] =
{
    {"上午", "shàngwǔ", "morning (before noon)", 1},
    {"下午", "xiàwǔ", "afternoon", 1},
    {"中午", "zhōngwǔ", "noon", 1},
};

// 谁
const VocabWord WORDS_U8C01[] =
{
    {"谁", "shéi", "who", 1},
};

// 什
const VocabWord WORDS_U4EC0[] =
{
    {"什么", "shénme", "what", 1},
    {"为什么", "wèi shénme", "why", 2},
};

// 么
const VocabWord WORDS_U4E48[] =
{
    {"什么", "shénme", "what", 1},
    {"怎么", "zěnme", "how; why", 1},
    {"怎么样", "zěnmeyàng", "how about; how is it", 1},
    {"为什么", "wèi shénme", "why", 2},
};

// 十
const VocabWord WORDS_U5341[] =
{
    {"十", "shí", "ten", 1},
};

// 时
const VocabWord WORDS_U65F6[] =
{
    {"时候", "shíhou", "time; moment", 1},
    {"时间", "shíjiān", "time", 2},
    {"小时", "xiǎoshí", "hour", 2},
};

// 候
const VocabWord WORDS_U5019[] =
{
    {"时候", "shíhou", "time; moment", 1},
};

// 是
const VocabWord WORDS_U662F[] =
{
    {"是", "shì", "to be (am/is/are)", 1},
    {"但是", "dànshì", "but", 2},
};

// 书
const VocabWord WORDS_U4E66[] =
{
    {"书", "shū", "book", 1},
};

// 水
const VocabWord WORDS_U6C34[] =
{
    {"水", "shuǐ", "water", 1},
    {"水果", "shuǐguǒ", "fruit", 1},
};

// 睡
const VocabWord WORDS_U7761[] =
{
    {"睡觉", "shuìjiào", "to sleep", 1},
};

// 觉
const VocabWord WORDS_U89C9[] =
{
    {"睡觉", "shuìjiào", "to sleep", 1},
    {"觉得", "juéde", "to feel; to think", 2},
};

// 说
const VocabWord WORDS_U8BF4[] =
{
    {"说", "shuō", "to speak; to say", 1},
    {"说话", "shuōhuà", "to talk", 2},
};

// 四
const VocabWord WORDS_U56DB[] =
{
    {"四", "sì", "four", 1},
};

// 岁
const VocabWord WORDS_U5C81[] =
{
    {"岁", "suì", "years old", 1},
};

// 他
const VocabWord WORDS_U4ED6[] =
{
    {"他", "tā", "he; him", 1},
};

// 她
const VocabWord WORDS_U5979[] =
{
    {"她", "tā", "she; her", 1},
};

// 太
const VocabWord WORDS_U592A[] =
{
    {"太", "tài", "too; extremely", 1},
};

// 听
const VocabWord WORDS_U542C[] =
{
    {"听", "tīng", "to listen", 1},
};

// 同
const VocabWord WORDS_U540C[] =
{
    {"同学", "tóngxué", "classmate", 1},
};

// 学
const VocabWord WORDS_U5B66[] =
{
    {"同学", "tóngxué", "classmate", 1},
    {"学生", "xuésheng", "student", 1},
    {"学习", "xuéxí", "to study", 1},
    {"学校", "xuéxiào", "school", 1},
};

// 喂
const VocabWord WORDS_U5582[] =
{
    {"喂", "wèi", "hello (on the phone)", 1},
};

// 我
const VocabWord WORDS_U6211[] =
{
    {"我", "wǒ", "I; me", 1},
    {"我们", "wǒmen", "we; us", 1},
};

// 们
const VocabWord WORDS_U4EEC[] =
{
    {"我们", "wǒmen", "we; us", 1},
};

// 五
const VocabWord WORDS_U4E94[] =
{
    {"五", "wǔ", "five", 1},
};

// 喜
const VocabWord WORDS_U559C[] =
{
    {"喜欢", "xǐhuan", "to like", 1},
};

// 欢
const VocabWord WORDS_U6B22[] =
{
    {"喜欢", "xǐhuan", "to like", 1},
};

// 下
const VocabWord WORDS_U4E0B[] =
{
    {"下", "xià", "down; below; next", 1},
    {"下午", "xiàwǔ", "afternoon", 1},
    {"下雨", "xiàyǔ", "to rain", 1},
    {"一下", "yíxià", "a bit; once", 2},
};

// 雨
const VocabWord WORDS_U96E8[] =
{
    {"下雨", "xiàyǔ", "to rain", 1},
};

// 先
const VocabWord WORDS_U5148[] =
{
    {"先生", "xiānsheng", "Mr.; sir; husband", 1},
};

// 生
const VocabWord WORDS_U751F[] =
{
    {"先生", "xiānsheng", "Mr.; sir; husband", 1},
    {"学生", "xuésheng", "student", 1},
    {"医生", "yīshēng", "doctor", 1},
    {"生病", "shēngbìng", "to get sick", 2},
    {"生日", "shēngrì", "birthday", 2},
};

// 现
const VocabWord WORDS_U73B0[] =
{
    {"现在", "xiànzài", "now", 1},
};

// 在
const VocabWord WORDS_U5728[] =
{
    {"在", "zài", "at; in; to be at", 1},
    {"现在", "xiànzài", "now", 1},
    {"正在", "zhèngzài", "in the middle of doing", 2},
};

// 想
const VocabWord WORDS_U60F3[] =
{
    {"想", "xiǎng", "to want; to think; to miss", 1},
};

// 小
const VocabWord WORDS_U5C0F[] =
{
    {"小", "xiǎo", "small; little", 1},
    {"小姐", "xiǎojiě", "Miss; young lady", 1},
    {"小时", "xiǎoshí", "hour", 2},
};

// 姐
const VocabWord WORDS_U59D0[] =
{
    {"小姐", "xiǎojiě", "Miss; young lady", 1},
    {"姐姐", "jiějie", "older sister", 2},
};

// 些
const VocabWord WORDS_U4E9B[] =
{
    {"些", "xiē", "some", 1},
};

// 写
const VocabWord WORDS_U5199[] =
{
    {"写", "xiě", "to write", 1},
};

// 谢
const VocabWord WORDS_U8C22[] =
{
    {"谢谢", "xièxie", "thank you", 1},
};

// 星
const VocabWord WORDS_U661F[] =
{
    {"星期", "xīngqī", "week", 1},
};

// 期
const VocabWord WORDS_U671F[] =
{
    {"星期", "xīngqī", "week", 1},
};

// 习
const VocabWord WORDS_U4E60[] =
{
    {"学习", "xuéxí", "to study", 1},
};

// 校
const VocabWord WORDS_U6821[] =
{
    {"学校", "xuéxiào", "school", 1},
};

// 一
const VocabWord WORDS_U4E00[] =
{
    {"一", "yī", "one", 1},
    {"一点儿", "yìdiǎnr", "a little", 1},
    {"第一", "dì-yī", "first", 2},
    {"一下", "yíxià", "a bit; once", 2},
    {"一起", "yìqǐ", "together", 2},
};

// 衣
const VocabWord WORDS_U8863[] =
{
    {"衣服", "yīfu", "clothes", 1},
};

// 服
const VocabWord WORDS_U670D[] =
{
    {"衣服", "yīfu", "clothes", 1},
    {"服务员", "fúwùyuán", "waiter; attendant", 2},
};

// 医
const VocabWord WORDS_U533B[] =
{
    {"医生", "yīshēng", "doctor", 1},
    {"医院", "yīyuàn", "hospital", 1},
};

// 院
const VocabWord WORDS_U9662[] =
{
    {"医院", "yīyuàn", "hospital", 1},
};

// 椅
const VocabWord WORDS_U6905[] =
{
    {"椅子", "yǐzi", "chair", 1},
};

// 月
const VocabWord WORDS_U6708[] =
{
    {"月", "yuè", "month; moon", 1},
};

// 再
const VocabWord WORDS_U518D[] =
{
    {"再", "zài", "again", 2},
    {"再见", "zàijiàn", "goodbye", 1},
};

// 怎
const VocabWord WORDS_U600E[] =
{
    {"怎么", "zěnme", "how; why", 1},
    {"怎么样", "zěnmeyàng", "how about; how is it", 1},
};

// 样
const VocabWord WORDS_U6837[] =
{
    {"怎么样", "zěnmeyàng", "how about; how is it", 1},
};

// 这
const VocabWord WORDS_U8FD9[] =
{
    {"这", "zhè", "this", 1},
};

// 中
const VocabWord WORDS_U4E2D[] =
{
    {"中国", "Zhōngguó", "China", 1},
    {"中午", "zhōngwǔ", "noon", 1},
};

// 国
const VocabWord WORDS_U56FD[] =
{
    {"中国", "Zhōngguó", "China", 1},
};

// 住
const VocabWord WORDS_U4F4F[] =
{
    {"住", "zhù", "to live; to stay", 1},
};

// 桌
const VocabWord WORDS_U684C[] =
{
    {"桌子", "zhuōzi", "table; desk", 1},
};

// 昨
const VocabWord WORDS_U6628[] =
{
    {"昨天", "zuótiān", "yesterday", 1},
};

// 坐
const VocabWord WORDS_U5750[] =
{
    {"坐", "zuò", "to sit; to take (a bus)", 1},
};

// 做
const VocabWord WORDS_U505A[] =
{
    {"做", "zuò", "to do; to make", 1},
};

// 吧
const VocabWord WORDS_U5427[] =
{
    {"吧", "ba", "particle: suggestion (let's)", 2},
};

// 白
const VocabWord WORDS_U767D[] =
{
    {"白", "bái", "white", 2},
};

// 百
const VocabWord WORDS_U767E[] =
{
    {"百", "bǎi", "hundred", 2},
};

// 帮
const VocabWord WORDS_U5E2E[] =
{
    {"帮助", "bāngzhù", "to help", 2},
};

// 助
const VocabWord WORDS_U52A9[] =
{
    {"帮助", "bāngzhù", "to help", 2},
};

// 报
const VocabWord WORDS_U62A5[] =
{
    {"报纸", "bàozhǐ", "newspaper", 2},
};

// 纸
const VocabWord WORDS_U7EB8[] =
{
    {"报纸", "bàozhǐ", "newspaper", 2},
};

// 比
const VocabWord WORDS_U6BD4[] =
{
    {"比", "bǐ", "than; compared with", 2},
};

// 别
const VocabWord WORDS_U522B[] =
{
    {"别", "bié", "don't", 2},
};

// 宾
const VocabWord WORDS_U5BBE[] =
{
    {"宾馆", "bīnguǎn", "hotel", 2},
};

// 馆
const VocabWord WORDS_U9986[] =
{
    {"宾馆", "bīnguǎn", "hotel", 2},
};

// 长
const VocabWord WORDS_U957F[] =
{
    {"长", "cháng", "long", 2},
};

// 唱
const VocabWord WORDS_U5531[] =
{
    {"唱歌", "chànggē", "to sing", 2},
};

// 歌
const VocabWord WORDS_U6B4C[] =
{
    {"唱歌", "chànggē", "to sing", 2},
};

// 穿
const VocabWord WORDS_U7A7F[] =
{
    {"穿", "chuān", "to wear; to put on", 2},
};

// 次
const VocabWord WORDS_U6B21[] =
{
    {"次", "cì", "time (occurrence)", 2},
};

// 从
const VocabWord WORDS_U4ECE[] =
{
    {"从", "cóng", "from", 2},
};

// 错
const VocabWord WORDS_U9519[] =
{
    {"错", "cuò", "wrong", 2},
};

// 篮
const VocabWord WORDS_U7BEE[] =
{
    {"打篮球", "dǎ lánqiú", "to play basketball", 2},
};

// 球
const VocabWord WORDS_U7403[] =
{
    {"打篮球", "dǎ lánqiú", "to play basketball", 2},
};

// 到
const VocabWord WORDS_U5230[] =
{
    {"到", "dào", "to arrive; to", 2},
};

// 得
const VocabWord WORDS_U5F97[] =
{
    {"得", "de", "particle after a verb", 2},
    {"觉得", "juéde", "to feel; to think", 2},
};

// 等
const VocabWord WORDS_U7B49[] =
{
    {"等", "děng", "to wait", 2},
};

// 弟
const VocabWord WORDS_U5F1F[] =
{
    {"弟弟", "dìdi", "younger brother", 2},
};

// 第
const VocabWord WORDS_U7B2C[] =
{
    {"第一", "dì-yī", "first", 2},
};

// 懂
const VocabWord WORDS_U61C2[] =
{
    {"懂", "dǒng", "to understand", 2},
};

// 房
const VocabWord WORDS_U623F[] =
{
    {"房间", "fángjiān", "room", 2},
};

// 间
const VocabWord WORDS_U95F4[] =
{
    {"房间", "fángjiān", "room", 2},
    {"时间", "shíjiān", "time", 2},
};

// 非
const VocabWord WORDS_U975E[] =
{
    {"非常", "fēicháng", "very; extremely", 2},
};

// 常
const VocabWord WORDS_U5E38[] =
{
    {"非常", "fēicháng", "very; extremely", 2},
};

// 务
const VocabWord WORDS_U52A1[] =
{
    {"服务员", "fúwùyuán", "waiter; attendant", 2},
};

// 员
const VocabWord WORDS_U5458[] =
{
    {"服务员", "fúwùyuán", "waiter; attendant", 2},
};

// 告
const VocabWord WORDS_U544A[] =
{
    {"告诉", "gàosu", "to tell", 2},
};

// 诉
const VocabWord WORDS_U8BC9[] =
{
    {"告诉", "gàosu", "to tell", 2},
};

// 哥
const VocabWord WORDS_U54E5[] =
{
    {"哥哥", "gēge", "older brother", 2},
};

// 给
const VocabWord WORDS_U7ED9[] =
{
    {"给", "gěi", "to give; for", 2},
};

// 公
const VocabWord WORDS_U516C[] =
{
    {"公共汽车", "gōnggòng qìchē", "bus", 2},
    {"公司", "gōngsī", "company", 2},
};

// 共
const VocabWord WORDS_U5171[] =
{
    {"公共汽车", "gōnggòng qìchē", "bus", 2},
};

// 汽
const VocabWord WORDS_U6C7D[] =
{
    {"公共汽车", "gōnggòng qìchē", "bus", 2},
};

// 司
const VocabWord WORDS_U53F8[] =
{
    {"公司", "gōngsī", "company", 2},
};

// 贵
const VocabWord WORDS_U8D35[] =
{
    {"贵", "guì", "expensive", 2},
};

// 过
const VocabWord WORDS_U8FC7[] =
{
    {"过", "guo", "particle: have done before", 2},
};

// 还
const VocabWord WORDS_U8FD8[] =
{
    {"还", "hái", "still; also", 2},
};

// 孩
const VocabWord WORDS_U5B69[] =
{
    {"孩子", "háizi", "child", 2},
};

// 黑
const VocabWord WORDS_U9ED1[] =
{
    {"黑", "hēi", "black; dark", 2},
};

// 红
const VocabWord WORDS_U7EA2[] =
{
    {"红", "hóng", "red", 2},
};

// 火
const VocabWord WORDS_U706B[] =
{
    {"火车站", "huǒchēzhàn", "train station", 2},
};

// 站
const VocabWord WORDS_U7AD9[] =
{
    {"火车站", "huǒchēzhàn", "train station", 2},
};

// 场
const VocabWord WORDS_U573A[] =
{
    {"机场", "jīchǎng", "airport", 2},
};

// 鸡
const VocabWord WORDS_U9E21[] =
{
    {"鸡蛋", "jīdàn", "egg", 2},
};

// 蛋
const VocabWord WORDS_U86CB[] =
{
    {"鸡蛋", "jīdàn", "egg", 2},
};

// 件
const VocabWord WORDS_U4EF6[] =
{
    {"件", "jiàn", "measure word for clothes, matters", 2},
};

// 教
const VocabWord WORDS_U6559[] =
{
    {"教室", "jiàoshì", "classroom", 2},
};

// 室
const VocabWord WORDS_U5BA4[] =
{
    {"教室", "jiàoshì", "classroom", 2},
};

// 介
const VocabWord WORDS_U4ECB[] =
{
    {"介绍", "jièshào", "to introduce", 2},
};

// 绍
const VocabWord WORDS_U7ECD[] =
{
    {"介绍", "jièshào", "to introduce", 2},
};

// 近
const VocabWord WORDS_U8FD1[] =
{
    {"近", "jìn", "near", 2},
};

// 进
const VocabWord WORDS_U8FDB[] =
{
    {"进", "jìn", "to enter", 2},
};

// 就
const VocabWord WORDS_U5C31[] =
{
    {"就", "jiù", "just; right away", 2},
};

// 咖
const VocabWord WORDS_U5496[] =
{
    {"咖啡", "kāfēi", "coffee", 2},
};

// 啡
const VocabWord WORDS_U5561[] =
{
    {"咖啡", "kāfēi", "coffee", 2},
};

// 始
const VocabWord WORDS_U59CB[] =
{
    {"开始", "kāishǐ", "to begin", 2},
};

// 考
const VocabWord WORDS_U8003[] =
{
    {"考试", "kǎoshì", "exam", 2},
};

// 试
const VocabWord WORDS_U8BD5[] =
{
    {"考试", "kǎoshì", "exam", 2},
};

// 可
const VocabWord WORDS_U53EF[] =
{
    {"可能", "kěnéng", "maybe; possible", 2},
    {"可以", "kěyǐ", "can; may", 2},
};

// 以
const VocabWord WORDS_U4EE5[] =
{
    {"可以", "kěyǐ", "can; may", 2},
    {"所以", "suǒyǐ", "so; therefore", 2},
};

// 课
const VocabWord WORDS_U8BFE[] =
{
    {"课", "kè", "class; lesson", 2},
};

// 快
const VocabWord WORDS_U5FEB[] =
{
    {"快", "kuài", "fast; quick", 2},
    {"快乐", "kuàilè", "happy", 2},
};

// 乐
const VocabWord WORDS_U4E50[] =
{
    {"快乐", "kuàilè", "happy", 2},
};

// 累
const VocabWord WORDS_U7D2F[] =
{
    {"累", "lèi", "tired", 2},
};

// 离
const VocabWord WORDS_U79BB[] =
{
    {"离", "lí", "away from", 2},
};

// 两
const VocabWord WORDS_U4E24[] =
{
    {"两", "liǎng", "two (of something)", 2},
};

// 零
const VocabWord WORDS_U96F6[] =
{
    {"零", "líng", "zero", 2},
};

// 路
const VocabWord WORDS_U8DEF[] =
{
    {"路", "lù", "road; way", 2},
};

// 旅
const VocabWord WORDS_U65C5[] =
{
    {"旅游", "lǚyóu", "to travel", 2},
};

// 游
const VocabWord WORDS_U6E38[] =
{
    {"旅游", "lǚyóu", "to travel", 2},
    {"游泳", "yóuyǒng", "to swim", 2},
};

// 卖
const VocabWord WORDS_U5356[] =
{
    {"卖", "mài", "to sell", 2},
};

// 慢
const VocabWord WORDS_U6162[] =
{
    {"慢", "màn", "slow", 2},
};

// 忙
const VocabWord WORDS_U5FD9[] =
{
    {"忙", "máng", "busy", 2},
};

// 每
const VocabWord WORDS_U6BCF[] =
{
    {"每", "měi", "every; each", 2},
};

// 妹
const VocabWord WORDS_U59B9[] =
{
    {"妹妹", "mèimei", "younger sister", 2},
};

// 门
const VocabWord WORDS_U95E8[] =
{
    {"门", "mén", "door", 2},
};

// 条
const VocabWord WORDS_U6761[] =
{
    {"面条", "miàntiáo", "noodles", 2},
};

// 男
const VocabWord WORDS_U7537[] =
{
    {"男", "nán", "male", 2},
};

// 您
const VocabWord WORDS_U60A8[] =
{
    {"您", "nín", "you (polite)", 2},
};

// 牛
const VocabWord WORDS_U725B[] =
{
    {"牛奶", "niúnǎi", "milk", 2},
};

// 奶
const VocabWord WORDS_U5976[] =
{
    {"牛奶", "niúnǎi", "milk", 2},
};

// 旁
const VocabWord WORDS_U65C1[] =
{
    {"旁边", "pángbiān", "beside", 2},
};

// 边
const VocabWord WORDS_U8FB9[] =
{
    {"旁边", "pángbiān", "beside", 2},
    {"右边", "yòubian", "right side", 2},
    {"左边", "zuǒbian", "left side", 2},
};

// 跑
const VocabWord WORDS_U8DD1[] =
{
    {"跑步", "pǎobù", "to run; to jog", 2},
};

// 步
const VocabWord WORDS_U6B65[] =
{
    {"跑步", "pǎobù", "to run; to jog", 2},
};

// 便
const VocabWord WORDS_U4FBF[] =
{
    {"便宜", "piányi", "cheap", 2},
};

// 宜
const VocabWord WORDS_U5B9C[] =
{
    {"便宜", "piányi", "cheap", 2},
};

// 票
const VocabWord WORDS_U7968[] =
{
    {"票", "piào", "ticket", 2},
};

// 妻
const VocabWord WORDS_U59BB[] =
{
    {"妻子", "qīzi", "wife", 2},
};

// 床
const VocabWord WORDS_U5E8A[] =
{
    {"起床", "qǐchuáng", "to get up", 2},
};

// 千
const VocabWord WORDS_U5343[] =
{
    {"千", "qiān", "thousand", 2},
};

// 铅
const VocabWord WORDS_U94C5[] =
{
    {"铅笔", "qiānbǐ", "pencil", 2},
};

// 笔
const VocabWord WORDS_U7B14[] =
{
    {"铅笔", "qiānbǐ", "pencil", 2},
};

// 晴
const VocabWord WORDS_U6674[] =
{
    {"晴", "qíng", "sunny; clear", 2},
};

// 让
const VocabWord WORDS_U8BA9[] =
{
    {"让", "ràng", "to let; to make", 2},
};

// 日
const VocabWord WORDS_U65E5[] =
{
    {"日", "rì", "day; sun", 2},
    {"生日", "shēngrì", "birthday", 2},
};

// 班
const VocabWord WORDS_U73ED[] =
{
    {"上班", "shàngbān", "to go to work", 2},
};

// 身
const VocabWord WORDS_U8EAB[] =
{
    {"身体", "shēntǐ", "body; health", 2},
};

// 体
const VocabWord WORDS_U4F53[] =
{
    {"身体", "shēntǐ", "body; health", 2},
};

// 病
const VocabWord WORDS_U75C5[] =
{
    {"生病", "shēngbìng", "to get sick", 2},
};

// 事
const VocabWord WORDS_U4E8B[] =
{
    {"事情", "shìqing", "matter; thing", 2},
};

// 情
const VocabWord WORDS_U60C5[] =
{
    {"事情", "shìqing", "matter; thing", 2},
};

// 手
const VocabWord WORDS_U624B[] =
{
    {"手表", "shǒubiǎo", "wristwatch", 2},
    {"手机", "shǒujī", "mobile phone", 2},
};

// 表
const VocabWord WORDS_U8868[] =
{
    {"手表", "shǒubiǎo", "wristwatch", 2},
};

// 送
const VocabWord WORDS_U9001[] =
{
    {"送", "sòng", "to give (a gift); to see off", 2},
};

// 虽
const VocabWord WORDS_U867D[] =
{
    {"虽然", "suīrán", "although", 2},
};

// 然
const VocabWord WORDS_U7136[] =
{
    {"虽然", "suīrán", "although", 2},
};

// 但
const VocabWord WORDS_U4F46[] =
{
    {"但是", "dànshì", "but", 2},
};

// 它
const VocabWord WORDS_U5B83[] =
{
    {"它", "tā", "it", 2},
};

// 踢
const VocabWord WORDS_U8E22[] =
{
    {"踢", "tī", "to kick", 2},
};

// 题
const VocabWord WORDS_U9898[] =
{
    {"题", "tí", "question (on a test)", 2},
    {"问题", "wèntí", "question; problem", 2},
};

// 跳
const VocabWord WORDS_U8DF3[] =
{
    {"跳舞", "tiàowǔ", "to dance", 2},
};

// 舞
const VocabWord WORDS_U821E[] =
{
    {"跳舞", "tiàowǔ", "to dance", 2},
};

// 外
const VocabWord WORDS_U5916[] =
{
    {"外", "wài", "outside", 2},
};

// 完
const VocabWord WORDS_U5B8C[] =
{
    {"完", "wán", "to finish", 2},
};

// 玩
const VocabWord WORDS_U73A9[] =
{
    {"玩", "wán", "to play; to have fun", 2},
};

// 晚
const VocabWord WORDS_U665A[] =
{
    {"晚上", "wǎnshang", "evening; night", 2},
};

// 往
const VocabWord WORDS_U5F80[] =
{
    {"往", "wǎng", "toward", 2},
};

// 为
const VocabWord WORDS_U4E3A[] =
{
    {"为什么", "wèi shénme", "why", 2},
    {"因为", "yīnwèi", "because", 2},
};

// 问
const VocabWord WORDS_U95EE[] =
{
    {"问", "wèn", "to ask", 2},
    {"问题", "wèntí", "question; problem", 2},
};

// 瓜
const VocabWord WORDS_U74DC[] =
{
    {"西瓜", "xīguā", "watermelon", 2},
};

// 希
const VocabWord WORDS_U5E0C[] =
{
    {"希望", "xīwàng", "to hope", 2},
};

// 望
const VocabWord WORDS_U671B[] =
{
    {"希望", "xīwàng", "to hope", 2},
};

// 洗
const VocabWord WORDS_U6D17[] =
{
    {"洗", "xǐ", "to wash", 2},
};

// 笑
const VocabWord WORDS_U7B11[] =
{
    {"笑", "xiào", "to laugh; to smile", 2},
};

// 新
const VocabWord WORDS_U65B0[] =
{
    {"新", "xīn", "new", 2},
};

// 姓
const VocabWord WORDS_U59D3[] =
{
    {"姓", "xìng", "surname", 2},
};

// 休
const VocabWord WORDS_U4F11[] =
{
    {"休息", "xiūxi", "to rest", 2},
};

// 息
const VocabWord WORDS_U606F[] =
{
    {"休息", "xiūxi", "to rest", 2},
};

// 雪
const VocabWord WORDS_U96EA[] =
{
    {"雪", "xuě", "snow", 2},
};

// 颜
const VocabWord WORDS_U989C[] =
{
    {"颜色", "yánsè", "color", 2},
};

// 色
const VocabWord WORDS_U8272[] =
{
    {"颜色", "yánsè", "color", 2},
};

// 眼
const VocabWord WORDS_U773C[] =
{
    {"眼睛", "yǎnjing", "eye", 2},
};

// 睛
const VocabWord WORDS_U775B[] =
{
    {"眼睛", "yǎnjing", "eye", 2},
};

// 羊
const VocabWord WORDS_U7F8A[] =
{
    {"羊肉", "yángròu", "mutton; lamb", 2},
};

// 肉
const VocabWord WORDS_U8089[] =
{
    {"羊肉", "yángròu", "mutton; lamb", 2},
};

// 要
const VocabWord WORDS_U8981[] =
{
    {"要", "yào", "to want; will", 2},
};

// 药
const VocabWord WORDS_U836F[] =
{
    {"药", "yào", "medicine", 2},
};

// 也
const VocabWord WORDS_U4E5F[] =
{
    {"也", "yě", "also", 2},
};

// 已
const VocabWord WORDS_U5DF2[] =
{
    {"已经", "yǐjīng", "already", 2},
};

// 经
const VocabWord WORDS_U7ECF[] =
{
    {"已经", "yǐjīng", "already", 2},
};

// 意
const VocabWord WORDS_U610F[] =
{
    {"意思", "yìsi", "meaning", 2},
};

// 思
const VocabWord WORDS_U601D[] =
{
    {"意思", "yìsi", "meaning", 2},
};

// 阴
const VocabWord WORDS_U9634[] =
{
    {"阴", "yīn", "cloudy; overcast", 2},
};

// 因
const VocabWord WORDS_U56E0[] =
{
    {"因为", "yīnwèi", "because", 2},
};

// 所
const VocabWord WORDS_U6240[] =
{
    {"所以", "suǒyǐ", "so; therefore", 2},
};

// 泳
const VocabWord WORDS_U6CF3[] =
{
    {"游泳", "yóuyǒng", "to swim", 2},
};

// 右
const VocabWord WORDS_U53F3[] =
{
    {"右边", "yòubian", "right side", 2},
};

// 鱼
const VocabWord WORDS_U9C7C[] =
{
    {"鱼", "yú", "fish", 2},
};

// 远
const VocabWord WORDS_U8FDC[] =
{
    {"远", "yuǎn", "far", 2},
};

// 运
const VocabWord WORDS_U8FD0[] =
{
    {"运动", "yùndòng", "sport; to exercise", 2},
};

// 动
const VocabWord WORDS_U52A8[] =
{
    {"运动", "yùndòng", "sport; to exercise", 2},
};

// 早
const VocabWord WORDS_U65E9[] =
{
    {"早上", "zǎoshang", "early morning", 2},
};

// 丈
const VocabWord WORDS_U4E08[] =
{
    {"丈夫", "zhàngfu", "husband", 2},
};

// 夫
const VocabWord WORDS_U592B[] =
{
    {"丈夫", "zhàngfu", "husband", 2},
};

// 找
const VocabWord WORDS_U627E[] =
{
    {"找", "zhǎo", "to look for", 2},
};

// 着
const VocabWord WORDS_U7740[] =
{
    {"着", "zhe", "particle: ongoing state", 2},
};

// 真
const VocabWord WORDS_U771F[] =
{
    {"真", "zhēn", "really; true", 2},
};

// 正
const VocabWord WORDS_U6B63[] =
{
    {"正在", "zhèngzài", "in the middle of doing", 2},
};

// 只
const VocabWord WORDS_U53EA[] =
{
    {"只", "zhī", "measure word for animals", 2},
};

// 知
const VocabWord WORDS_U77E5[] =
{
    {"知道", "zhīdào", "to know", 2},
};

// 道
const VocabWord WORDS_U9053[] =
{
    {"知道", "zhīdào", "to know", 2},
};

// 准
const VocabWord WORDS_U51C6[] =
{
    {"准备", "zhǔnbèi", "to prepare", 2},
};

// 备
const VocabWord WORDS_U5907[] =
{
    {"准备", "zhǔnbèi", "to prepare", 2},
};

// 走
const VocabWord WORDS_U8D70[] =
{
    {"走", "zǒu", "to walk; to leave", 2},
};

// 最
const VocabWord WORDS_U6700[] =
{
    {"最", "zuì", "most", 2},
};

// 左
const VocabWord WORDS_U5DE6[] =
{
    {"左边", "zuǒbian", "left side", 2},
};

const HanziCard CARDS[] =
{
    // 爱
    {
        hanzi_7231,
        hanzi_7231_width,
        hanzi_7231_height,
        1,
        "ài",
        "love; to love",
        WORDS_U7231,
        1,
    },
    // 八
    {
        hanzi_516B,
        hanzi_516B_width,
        hanzi_516B_height,
        1,
        "bā",
        "eight",
        WORDS_U516B,
        1,
    },
    // 爸
    {
        hanzi_7238,
        hanzi_7238_width,
        hanzi_7238_height,
        1,
        "bà",
        "dad; father",
        WORDS_U7238,
        1,
    },
    // 杯
    {
        hanzi_676F,
        hanzi_676F_width,
        hanzi_676F_height,
        1,
        "bēi",
        "cup; glass",
        WORDS_U676F,
        1,
    },
    // 子
    {
        hanzi_5B50,
        hanzi_5B50_width,
        hanzi_5B50_height,
        1,
        "zǐ / zi",
        "child; noun suffix",
        WORDS_U5B50,
        6,
    },
    // 北
    {
        hanzi_5317,
        hanzi_5317_width,
        hanzi_5317_height,
        1,
        "běi",
        "north",
        WORDS_U5317,
        1,
    },
    // 京
    {
        hanzi_4EAC,
        hanzi_4EAC_width,
        hanzi_4EAC_height,
        1,
        "jīng",
        "capital city",
        WORDS_U4EAC,
        1,
    },
    // 本
    {
        hanzi_672C,
        hanzi_672C_width,
        hanzi_672C_height,
        1,
        "běn",
        "root; origin; measure word for books",
        WORDS_U672C,
        1,
    },
    // 不
    {
        hanzi_4E0D,
        hanzi_4E0D_width,
        hanzi_4E0D_height,
        1,
        "bù",
        "not; no",
        WORDS_U4E0D,
        3,
    },
    // 客
    {
        hanzi_5BA2,
        hanzi_5BA2_width,
        hanzi_5BA2_height,
        1,
        "kè",
        "guest; visitor",
        WORDS_U5BA2,
        1,
    },
    // 气
    {
        hanzi_6C14,
        hanzi_6C14_width,
        hanzi_6C14_height,
        1,
        "qì",
        "air; gas; anger",
        WORDS_U6C14,
        2,
    },
    // 菜
    {
        hanzi_83DC,
        hanzi_83DC_width,
        hanzi_83DC_height,
        1,
        "cài",
        "dish; vegetable",
        WORDS_U83DC,
        1,
    },
    // 茶
    {
        hanzi_8336,
        hanzi_8336_width,
        hanzi_8336_height,
        1,
        "chá",
        "tea",
        WORDS_U8336,
        1,
    },
    // 吃
    {
        hanzi_5403,
        hanzi_5403_width,
        hanzi_5403_height,
        1,
        "chī",
        "to eat",
        WORDS_U5403,
        2,
    },
    // 出
    {
        hanzi_51FA,
        hanzi_51FA_width,
        hanzi_51FA_height,
        1,
        "chū",
        "to go out; to come out",
        WORDS_U51FA,
        2,
    },
    // 租
    {
        hanzi_79DF,
        hanzi_79DF_width,
        hanzi_79DF_height,
        1,
        "zū",
        "to rent",
        WORDS_U79DF,
        1,
    },
    // 车
    {
        hanzi_8F66,
        hanzi_8F66_width,
        hanzi_8F66_height,
        1,
        "chē",
        "vehicle; car",
        WORDS_U8F66,
        3,
    },
    // 打
    {
        hanzi_6253,
        hanzi_6253_width,
        hanzi_6253_height,
        1,
        "dǎ",
        "to hit; to play (ball); to make (a call)",
        WORDS_U6253,
        2,
    },
    // 电
    {
        hanzi_7535,
        hanzi_7535_width,
        hanzi_7535_height,
        1,
        "diàn",
        "electricity",
        WORDS_U7535,
        4,
    },
    // 话
    {
        hanzi_8BDD,
        hanzi_8BDD_width,
        hanzi_8BDD_height,
        1,
        "huà",
        "speech; words",
        WORDS_U8BDD,
        2,
    },
    // 大
    {
        hanzi_5927,
        hanzi_5927_width,
        hanzi_5927_height,
        1,
        "dà",
        "big; large",
        WORDS_U5927,
        2,
    },
    // 的
    {
        hanzi_7684,
        hanzi_7684_width,
        hanzi_7684_height,
        1,
        "de",
        "possessive particle",
        WORDS_U7684,
        1,
    },
    // 点
    {
        hanzi_70B9,
        hanzi_70B9_width,
        hanzi_70B9_height,
        1,
        "diǎn",
        "dot; point; o'clock",
        WORDS_U70B9,
        2,
    },
    // 脑
    {
        hanzi_8111,
        hanzi_8111_width,
        hanzi_8111_height,
        1,
        "nǎo",
        "brain",
        WORDS_U8111,
        1,
    },
    // 视
    {
        hanzi_89C6,
        hanzi_89C6_width,
        hanzi_89C6_height,
        1,
        "shì",
        "to look at; vision",
        WORDS_U89C6,
        1,
    },
    // 影
    {
        hanzi_5F71,
        hanzi_5F71_width,
        hanzi_5F71_height,
        1,
        "yǐng",
        "shadow; image",
        WORDS_U5F71,
        1,
    },
    // 东
    {
        hanzi_4E1C,
        hanzi_4E1C_width,
        hanzi_4E1C_height,
        1,
        "dōng",
        "east",
        WORDS_U4E1C,
        1,
    },
    // 西
    {
        hanzi_897F,
        hanzi_897F_width,
        hanzi_897F_height,
        1,
        "xī",
        "west",
        WORDS_U897F,
        2,
    },
    // 都
    {
        hanzi_90FD,
        hanzi_90FD_width,
        hanzi_90FD_height,
        1,
        "dōu",
        "all; both",
        WORDS_U90FD,
        1,
    },
    // 读
    {
        hanzi_8BFB,
        hanzi_8BFB_width,
        hanzi_8BFB_height,
        1,
        "dú",
        "to read (aloud)",
        WORDS_U8BFB,
        1,
    },
    // 对
    {
        hanzi_5BF9,
        hanzi_5BF9_width,
        hanzi_5BF9_height,
        1,
        "duì",
        "correct; toward; to face",
        WORDS_U5BF9,
        2,
    },
    // 起
    {
        hanzi_8D77,
        hanzi_8D77_width,
        hanzi_8D77_height,
        1,
        "qǐ",
        "to rise; to get up",
        WORDS_U8D77,
        3,
    },
    // 多
    {
        hanzi_591A,
        hanzi_591A_width,
        hanzi_591A_height,
        1,
        "duō",
        "many; much",
        WORDS_U591A,
        2,
    },
    // 少
    {
        hanzi_5C11,
        hanzi_5C11_width,
        hanzi_5C11_height,
        1,
        "shǎo",
        "few; little",
        WORDS_U5C11,
        2,
    },
    // 儿
    {
        hanzi_513F,
        hanzi_513F_width,
        hanzi_513F_height,
        1,
        "ér / -r",
        "child; son; -r suffix",
        WORDS_U513F,
        4,
    },
    // 二
    {
        hanzi_4E8C,
        hanzi_4E8C_width,
        hanzi_4E8C_height,
        1,
        "èr",
        "two",
        WORDS_U4E8C,
        1,
    },
    // 饭
    {
        hanzi_996D,
        hanzi_996D_width,
        hanzi_996D_height,
        1,
        "fàn",
        "cooked rice; meal",
        WORDS_U996D,
        2,
    },
    // 店
    {
        hanzi_5E97,
        hanzi_5E97_width,
        hanzi_5E97_height,
        1,
        "diàn",
        "shop; store",
        WORDS_U5E97,
        2,
    },
    // 飞
    {
        hanzi_98DE,
        hanzi_98DE_width,
        hanzi_98DE_height,
        1,
        "fēi",
        "to fly",
        WORDS_U98DE,
        1,
    },
    // 机
    {
        hanzi_673A,
        hanzi_673A_width,
        hanzi_673A_height,
        1,
        "jī",
        "machine; chance",
        WORDS_U673A,
        3,
    },
    // 分
    {
        hanzi_5206,
        hanzi_5206_width,
        hanzi_5206_height,
        1,
        "fēn",
        "to divide; minute; cent",
        WORDS_U5206,
        1,
    },
    // 钟
    {
        hanzi_949F,
        hanzi_949F_width,
        hanzi_949F_height,
        1,
        "zhōng",
        "clock; bell",
        WORDS_U949F,
        1,
    },
    // 高
    {
        hanzi_9AD8,
        hanzi_9AD8_width,
        hanzi_9AD8_height,
        1,
        "gāo",
        "tall; high",
        WORDS_U9AD8,
        2,
    },
    // 兴
    {
        hanzi_5174,
        hanzi_5174_width,
        hanzi_5174_height,
        1,
        "xìng",
        "interest; mood",
        WORDS_U5174,
        1,
    },
    // 个
    {
        hanzi_4E2A,
        hanzi_4E2A_width,
        hanzi_4E2A_height,
        1,
        "gè",
        "general measure word",
        WORDS_U4E2A,
        1,
    },
    // 工
    {
        hanzi_5DE5,
        hanzi_5DE5_width,
        hanzi_5DE5_height,
        1,
        "gōng",
        "work; worker",
        WORDS_U5DE5,
        1,
    },
    // 作
    {
        hanzi_4F5C,
        hanzi_4F5C_width,
        hanzi_4F5C_height,
        1,
        "zuò",
        "to do; to make",
        WORDS_U4F5C,
        1,
    },
    // 狗
    {
        hanzi_72D7,
        hanzi_72D7_width,
        hanzi_72D7_height,
        1,
        "gǒu",
        "dog",
        WORDS_U72D7,
        1,
    },
    // 汉
    {
        hanzi_6C49,
        hanzi_6C49_width,
        hanzi_6C49_height,
        1,
        "hàn",
        "Han Chinese",
        WORDS_U6C49,
        1,
    },
    // 语
    {
        hanzi_8BED,
        hanzi_8BED_width,
        hanzi_8BED_height,
        1,
        "yǔ",
        "language",
        WORDS_U8BED,
        1,
    },
    // 好
    {
        hanzi_597D,
        hanzi_597D_width,
        hanzi_597D_height,
        1,
        "hǎo",
        "good; well",
        WORDS_U597D,
        2,
    },
    // 号
    {
        hanzi_53F7,
        hanzi_53F7_width,
        hanzi_53F7_height,
        1,
        "hào",
        "number; date",
        WORDS_U53F7,
        1,
    },
    // 喝
    {
        hanzi_559D,
        hanzi_559D_width,
        hanzi_559D_height,
        1,
        "hē",
        "to drink",
        WORDS_U559D,
        1,
    },
    // 和
    {
        hanzi_548C,
        hanzi_548C_width,
        hanzi_548C_height,
        1,
        "hé",
        "and; with; peace",
        WORDS_U548C,
        1,
    },
    // 很
    {
        hanzi_5F88,
        hanzi_5F88_width,
        hanzi_5F88_height,
        1,
        "hěn",
        "very",
        WORDS_U5F88,
        1,
    },
    // 后
    {
        hanzi_540E,
        hanzi_540E_width,
        hanzi_540E_height,
        1,
        "hòu",
        "behind; after",
        WORDS_U540E,
        1,
    },
    // 面
    {
        hanzi_9762,
        hanzi_9762_width,
        hanzi_9762_height,
        1,
        "miàn",
        "face; side; noodles",
        WORDS_U9762,
        3,
    },
    // 回
    {
        hanzi_56DE,
        hanzi_56DE_width,
        hanzi_56DE_height,
        1,
        "huí",
        "to return",
        WORDS_U56DE,
        1,
    },
    // 会
    {
        hanzi_4F1A,
        hanzi_4F1A_width,
        hanzi_4F1A_height,
        1,
        "huì",
        "can; to know how to; meeting",
        WORDS_U4F1A,
        1,
    },
    // 几
    {
        hanzi_51E0,
        hanzi_51E0_width,
        hanzi_51E0_height,
        1,
        "jǐ",
        "how many; a few",
        WORDS_U51E0,
        1,
    },
    // 家
    {
        hanzi_5BB6,
        hanzi_5BB6_width,
        hanzi_5BB6_height,
        1,
        "jiā",
        "home; family",
        WORDS_U5BB6,
        2,
    },
    // 叫
    {
        hanzi_53EB,
        hanzi_53EB_width,
        hanzi_53EB_height,
        1,
        "jiào",
        "to call; to be called",
        WORDS_U53EB,
        1,
    },
    // 今
    {
        hanzi_4ECA,
        hanzi_4ECA_width,
        hanzi_4ECA_height,
        1,
        "jīn",
        "now; today",
        WORDS_U4ECA,
        1,
    },
    // 天
    {
        hanzi_5929,
        hanzi_5929_width,
        hanzi_5929_height,
        1,
        "tiān",
        "sky; day",
        WORDS_U5929,
        4,
    },
    // 九
    {
        hanzi_4E5D,
        hanzi_4E5D_width,
        hanzi_4E5D_height,
        1,
        "jiǔ",
        "nine",
        WORDS_U4E5D,
        1,
    },
    // 开
    {
        hanzi_5F00,
        hanzi_5F00_width,
        hanzi_5F00_height,
        1,
        "kāi",
        "to open; to drive",
        WORDS_U5F00,
        2,
    },
    // 看
    {
        hanzi_770B,
        hanzi_770B_width,
        hanzi_770B_height,
        1,
        "kàn",
        "to look; to watch",
        WORDS_U770B,
        2,
    },
    // 见
    {
        hanzi_89C1,
        hanzi_89C1_width,
        hanzi_89C1_height,
        1,
        "jiàn",
        "to see; to meet",
        WORDS_U89C1,
        2,
    },
    // 块
    {
        hanzi_5757,
        hanzi_5757_width,
        hanzi_5757_height,
        1,
        "kuài",
        "piece; yuan (money)",
        WORDS_U5757,
        1,
    },
    // 来
    {
        hanzi_6765,
        hanzi_6765_width,
        hanzi_6765_height,
        1,
        "lái",
        "to come",
        WORDS_U6765,
        1,
    },
    // 老
    {
        hanzi_8001,
        hanzi_8001_width,
        hanzi_8001_height,
        1,
        "lǎo",
        "old",
        WORDS_U8001,
        1,
    },
    // 师
    {
        hanzi_5E08,
        hanzi_5E08_width,
        hanzi_5E08_height,
        1,
        "shī",
        "teacher; master",
        WORDS_U5E08,
        1,
    },
    // 了
    {
        hanzi_4E86,
        hanzi_4E86_width,
        hanzi_4E86_height,
        1,
        "le",
        "particle: completed action",
        WORDS_U4E86,
        1,
    },
    // 冷
    {
        hanzi_51B7,
        hanzi_51B7_width,
        hanzi_51B7_height,
        1,
        "lěng",
        "cold",
        WORDS_U51B7,
        1,
    },
    // 里
    {
        hanzi_91CC,
        hanzi_91CC_width,
        hanzi_91CC_height,
        1,
        "lǐ",
        "inside",
        WORDS_U91CC,
        1,
    },
    // 六
    {
        hanzi_516D,
        hanzi_516D_width,
        hanzi_516D_height,
        1,
        "liù",
        "six",
        WORDS_U516D,
        1,
    },
    // 妈
    {
        hanzi_5988,
        hanzi_5988_width,
        hanzi_5988_height,
        1,
        "mā",
        "mom; mother",
        WORDS_U5988,
        1,
    },
    // 吗
    {
        hanzi_5417,
        hanzi_5417_width,
        hanzi_5417_height,
        1,
        "ma",
        "question particle",
        WORDS_U5417,
        1,
    },
    // 买
    {
        hanzi_4E70,
        hanzi_4E70_width,
        hanzi_4E70_height,
        1,
        "mǎi",
        "to buy",
        WORDS_U4E70,
        1,
    },
    // 猫
    {
        hanzi_732B,
        hanzi_732B_width,
        hanzi_732B_height,
        1,
        "māo",
        "cat",
        WORDS_U732B,
        1,
    },
    // 没
    {
        hanzi_6CA1,
        hanzi_6CA1_width,
        hanzi_6CA1_height,
        1,
        "méi",
        "not (have)",
        WORDS_U6CA1,
        2,
    },
    // 关
    {
        hanzi_5173,
        hanzi_5173_width,
        hanzi_5173_height,
        1,
        "guān",
        "to close; to concern",
        WORDS_U5173,
        1,
    },
    // 系
    {
        hanzi_7CFB,
        hanzi_7CFB_width,
        hanzi_7CFB_height,
        1,
        "xì",
        "system; to relate",
        WORDS_U7CFB,
        1,
    },
    // 有
    {
        hanzi_6709,
        hanzi_6709_width,
        hanzi_6709_height,
        1,
        "yǒu",
        "to have; there is",
        WORDS_U6709,
        2,
    },
    // 米
    {
        hanzi_7C73,
        hanzi_7C73_width,
        hanzi_7C73_height,
        1,
        "mǐ",
        "rice (uncooked); meter",
        WORDS_U7C73,
        1,
    },
    // 明
    {
        hanzi_660E,
        hanzi_660E_width,
        hanzi_660E_height,
        1,
        "míng",
        "bright; next (day, year)",
        WORDS_U660E,
        1,
    },
    // 名
    {
        hanzi_540D,
        hanzi_540D_width,
        hanzi_540D_height,
        1,
        "míng",
        "name",
        WORDS_U540D,
        1,
    },
    // 字
    {
        hanzi_5B57,
        hanzi_5B57_width,
        hanzi_5B57_height,
        1,
        "zì",
        "character; word",
        WORDS_U5B57,
        2,
    },
    // 哪
    {
        hanzi_54EA,
        hanzi_54EA_width,
        hanzi_54EA_height,
        1,
        "nǎ",
        "which",
        WORDS_U54EA,
        2,
    },
    // 那
    {
        hanzi_90A3,
        hanzi_90A3_width,
        hanzi_90A3_height,
        1,
        "nà",
        "that",
        WORDS_U90A3,
        1,
    },
    // 呢
    {
        hanzi_5462,
        hanzi_5462_width,
        hanzi_5462_height,
        1,
        "ne",
        "particle: and you? / still",
        WORDS_U5462,
        1,
    },
    // 能
    {
        hanzi_80FD,
        hanzi_80FD_width,
        hanzi_80FD_height,
        1,
        "néng",
        "can; be able to",
        WORDS_U80FD,
        2,
    },
    // 你
    {
        hanzi_4F60,
        hanzi_4F60_width,
        hanzi_4F60_height,
        1,
        "nǐ",
        "you",
        WORDS_U4F60,
        1,
    },
    // 年
    {
        hanzi_5E74,
        hanzi_5E74_width,
        hanzi_5E74_height,
        1,
        "nián",
        "year",
        WORDS_U5E74,
        2,
    },
    // 女
    {
        hanzi_5973,
        hanzi_5973_width,
        hanzi_5973_height,
        1,
        "nǚ",
        "female; woman",
        WORDS_U5973,
        2,
    },
    // 朋
    {
        hanzi_670B,
        hanzi_670B_width,
        hanzi_670B_height,
        1,
        "péng",
        "friend",
        WORDS_U670B,
        1,
    },
    // 友
    {
        hanzi_53CB,
        hanzi_53CB_width,
        hanzi_53CB_height,
        1,
        "yǒu",
        "friend",
        WORDS_U53CB,
        1,
    },
    // 漂
    {
        hanzi_6F02,
        hanzi_6F02_width,
        hanzi_6F02_height,
        1,
        "piào / piāo",
        "used in 'pretty'; to float",
        WORDS_U6F02,
        1,
    },
    // 亮
    {
        hanzi_4EAE,
        hanzi_4EAE_width,
        hanzi_4EAE_height,
        1,
        "liàng",
        "bright",
        WORDS_U4EAE,
        1,
    },
    // 苹
    {
        hanzi_82F9,
        hanzi_82F9_width,
        hanzi_82F9_height,
        1,
        "píng",
        "used in 'apple'",
        WORDS_U82F9,
        1,
    },
    // 果
    {
        hanzi_679C,
        hanzi_679C_width,
        hanzi_679C_height,
        1,
        "guǒ",
        "fruit; result",
        WORDS_U679C,
        2,
    },
    // 七
    {
        hanzi_4E03,
        hanzi_4E03_width,
        hanzi_4E03_height,
        1,
        "qī",
        "seven",
        WORDS_U4E03,
        1,
    },
    // 钱
    {
        hanzi_94B1,
        hanzi_94B1_width,
        hanzi_94B1_height,
        1,
        "qián",
        "money",
        WORDS_U94B1,
        1,
    },
    // 前
    {
        hanzi_524D,
        hanzi_524D_width,
        hanzi_524D_height,
        1,
        "qián",
        "front; before",
        WORDS_U524D,
        1,
    },
    // 请
    {
        hanzi_8BF7,
        hanzi_8BF7_width,
        hanzi_8BF7_height,
        1,
        "qǐng",
        "please; to invite",
        WORDS_U8BF7,
        1,
    },
    // 去
    {
        hanzi_53BB,
        hanzi_53BB_width,
        hanzi_53BB_height,
        1,
        "qù",
        "to go",
        WORDS_U53BB,
        2,
    },
    // 热
    {
        hanzi_70ED,
        hanzi_70ED_width,
        hanzi_70ED_height,
        1,
        "rè",
        "hot",
        WORDS_U70ED,
        1,
    },
    // 人
    {
        hanzi_4EBA,
        hanzi_4EBA_width,
        hanzi_4EBA_height,
        1,
        "rén",
        "person",
        WORDS_U4EBA,
        1,
    },
    // 认
    {
        hanzi_8BA4,
        hanzi_8BA4_width,
        hanzi_8BA4_height,
        1,
        "rèn",
        "to recognize",
        WORDS_U8BA4,
        1,
    },
    // 识
    {
        hanzi_8BC6,
        hanzi_8BC6_width,
        hanzi_8BC6_height,
        1,
        "shí",
        "to know; knowledge",
        WORDS_U8BC6,
        1,
    },
    // 三
    {
        hanzi_4E09,
        hanzi_4E09_width,
        hanzi_4E09_height,
        1,
        "sān",
        "three",
        WORDS_U4E09,
        1,
    },
    // 商
    {
        hanzi_5546,
        hanzi_5546_width,
        hanzi_5546_height,
        1,
        "shāng",
        "trade; business",
        WORDS_U5546,
        1,
    },
    // 上
    {
        hanzi_4E0A,
        hanzi_4E0A_width,
        hanzi_4E0A_height,
        1,
        "shàng",
        "up; on; above",
        WORDS_U4E0A,
        5,
    },
    // 午
    {
        hanzi_5348,
        hanzi_5348_width,
        hanzi_5348_height,
        1,
        "wǔ",
        "noon",
        WORDS_U5348,
        3,
    },
    // 谁
    {
        hanzi_8C01,
        hanzi_8C01_width,
        hanzi_8C01_height,
        1,
        "shéi / shuí",
        "who",
        WORDS_U8C01,
        1,
    },
    // 什
    {
        hanzi_4EC0,
        hanzi_4EC0_width,
        hanzi_4EC0_height,
        1,
        "shén",
        "used in 'what'",
        WORDS_U4EC0,
        2,
    },
    // 么
    {
        hanzi_4E48,
        hanzi_4E48_width,
        hanzi_4E48_height,
        1,
        "me",
        "suffix in 'what', 'how', 'why'",
        WORDS_U4E48,
        4,
    },
    // 十
    {
        hanzi_5341,
        hanzi_5341_width,
        hanzi_5341_height,
        1,
        "shí",
        "ten",
        WORDS_U5341,
        1,
    },
    // 时
    {
        hanzi_65F6,
        hanzi_65F6_width,
        hanzi_65F6_height,
        1,
        "shí",
        "time; hour",
        WORDS_U65F6,
        3,
    },
    // 候
    {
        hanzi_5019,
        hanzi_5019_width,
        hanzi_5019_height,
        1,
        "hòu",
        "to wait; time; season",
        WORDS_U5019,
        1,
    },
    // 是
    {
        hanzi_662F,
        hanzi_662F_width,
        hanzi_662F_height,
        1,
        "shì",
        "to be; yes",
        WORDS_U662F,
        2,
    },
    // 书
    {
        hanzi_4E66,
        hanzi_4E66_width,
        hanzi_4E66_height,
        1,
        "shū",
        "book",
        WORDS_U4E66,
        1,
    },
    // 水
    {
        hanzi_6C34,
        hanzi_6C34_width,
        hanzi_6C34_height,
        1,
        "shuǐ",
        "water",
        WORDS_U6C34,
        2,
    },
    // 睡
    {
        hanzi_7761,
        hanzi_7761_width,
        hanzi_7761_height,
        1,
        "shuì",
        "to sleep",
        WORDS_U7761,
        1,
    },
    // 觉
    {
        hanzi_89C9,
        hanzi_89C9_width,
        hanzi_89C9_height,
        1,
        "jiào / jué",
        "sleep; to feel",
        WORDS_U89C9,
        2,
    },
    // 说
    {
        hanzi_8BF4,
        hanzi_8BF4_width,
        hanzi_8BF4_height,
        1,
        "shuō",
        "to speak; to say",
        WORDS_U8BF4,
        2,
    },
    // 四
    {
        hanzi_56DB,
        hanzi_56DB_width,
        hanzi_56DB_height,
        1,
        "sì",
        "four",
        WORDS_U56DB,
        1,
    },
    // 岁
    {
        hanzi_5C81,
        hanzi_5C81_width,
        hanzi_5C81_height,
        1,
        "suì",
        "years of age",
        WORDS_U5C81,
        1,
    },
    // 他
    {
        hanzi_4ED6,
        hanzi_4ED6_width,
        hanzi_4ED6_height,
        1,
        "tā",
        "he; him",
        WORDS_U4ED6,
        1,
    },
    // 她
    {
        hanzi_5979,
        hanzi_5979_width,
        hanzi_5979_height,
        1,
        "tā",
        "she; her",
        WORDS_U5979,
        1,
    },
    // 太
    {
        hanzi_592A,
        hanzi_592A_width,
        hanzi_592A_height,
        1,
        "tài",
        "too; extremely",
        WORDS_U592A,
        1,
    },
    // 听
    {
        hanzi_542C,
        hanzi_542C_width,
        hanzi_542C_height,
        1,
        "tīng",
        "to listen",
        WORDS_U542C,
        1,
    },
    // 同
    {
        hanzi_540C,
        hanzi_540C_width,
        hanzi_540C_height,
        1,
        "tóng",
        "same; together",
        WORDS_U540C,
        1,
    },
    // 学
    {
        hanzi_5B66,
        hanzi_5B66_width,
        hanzi_5B66_height,
        1,
        "xué",
        "to study; to learn",
        WORDS_U5B66,
        4,
    },
    // 喂
    {
        hanzi_5582,
        hanzi_5582_width,
        hanzi_5582_height,
        1,
        "wèi",
        "hello (on the phone); to feed",
        WORDS_U5582,
        1,
    },
    // 我
    {
        hanzi_6211,
        hanzi_6211_width,
        hanzi_6211_height,
        1,
        "wǒ",
        "I; me",
        WORDS_U6211,
        2,
    },
    // 们
    {
        hanzi_4EEC,
        hanzi_4EEC_width,
        hanzi_4EEC_height,
        1,
        "men",
        "plural suffix for people",
        WORDS_U4EEC,
        1,
    },
    // 五
    {
        hanzi_4E94,
        hanzi_4E94_width,
        hanzi_4E94_height,
        1,
        "wǔ",
        "five",
        WORDS_U4E94,
        1,
    },
    // 喜
    {
        hanzi_559C,
        hanzi_559C_width,
        hanzi_559C_height,
        1,
        "xǐ",
        "happy; to like",
        WORDS_U559C,
        1,
    },
    // 欢
    {
        hanzi_6B22,
        hanzi_6B22_width,
        hanzi_6B22_height,
        1,
        "huān",
        "joyful; glad",
        WORDS_U6B22,
        1,
    },
    // 下
    {
        hanzi_4E0B,
        hanzi_4E0B_width,
        hanzi_4E0B_height,
        1,
        "xià",
        "down; below; next",
        WORDS_U4E0B,
        4,
    },
    // 雨
    {
        hanzi_96E8,
        hanzi_96E8_width,
        hanzi_96E8_height,
        1,
        "yǔ",
        "rain",
        WORDS_U96E8,
        1,
    },
    // 先
    {
        hanzi_5148,
        hanzi_5148_width,
        hanzi_5148_height,
        1,
        "xiān",
        "first; before",
        WORDS_U5148,
        1,
    },
    // 生
    {
        hanzi_751F,
        hanzi_751F_width,
        hanzi_751F_height,
        1,
        "shēng",
        "to be born; life; raw",
        WORDS_U751F,
        5,
    },
    // 现
    {
        hanzi_73B0,
        hanzi_73B0_width,
        hanzi_73B0_height,
        1,
        "xiàn",
        "present; now; to appear",
        WORDS_U73B0,
        1,
    },
    // 在
    {
        hanzi_5728,
        hanzi_5728_width,
        hanzi_5728_height,
        1,
        "zài",
        "at; in; to exist",
        WORDS_U5728,
        3,
    },
    // 想
    {
        hanzi_60F3,
        hanzi_60F3_width,
        hanzi_60F3_height,
        1,
        "xiǎng",
        "to want; to think; to miss",
        WORDS_U60F3,
        1,
    },
    // 小
    {
        hanzi_5C0F,
        hanzi_5C0F_width,
        hanzi_5C0F_height,
        1,
        "xiǎo",
        "small; little",
        WORDS_U5C0F,
        3,
    },
    // 姐
    {
        hanzi_59D0,
        hanzi_59D0_width,
        hanzi_59D0_height,
        1,
        "jiě",
        "older sister; Miss",
        WORDS_U59D0,
        2,
    },
    // 些
    {
        hanzi_4E9B,
        hanzi_4E9B_width,
        hanzi_4E9B_height,
        1,
        "xiē",
        "some",
        WORDS_U4E9B,
        1,
    },
    // 写
    {
        hanzi_5199,
        hanzi_5199_width,
        hanzi_5199_height,
        1,
        "xiě",
        "to write",
        WORDS_U5199,
        1,
    },
    // 谢
    {
        hanzi_8C22,
        hanzi_8C22_width,
        hanzi_8C22_height,
        1,
        "xiè",
        "to thank",
        WORDS_U8C22,
        1,
    },
    // 星
    {
        hanzi_661F,
        hanzi_661F_width,
        hanzi_661F_height,
        1,
        "xīng",
        "star",
        WORDS_U661F,
        1,
    },
    // 期
    {
        hanzi_671F,
        hanzi_671F_width,
        hanzi_671F_height,
        1,
        "qī",
        "period of time",
        WORDS_U671F,
        1,
    },
    // 习
    {
        hanzi_4E60,
        hanzi_4E60_width,
        hanzi_4E60_height,
        1,
        "xí",
        "to practice",
        WORDS_U4E60,
        1,
    },
    // 校
    {
        hanzi_6821,
        hanzi_6821_width,
        hanzi_6821_height,
        1,
        "xiào",
        "school",
        WORDS_U6821,
        1,
    },
    // 一
    {
        hanzi_4E00,
        hanzi_4E00_width,
        hanzi_4E00_height,
        1,
        "yī",
        "one",
        WORDS_U4E00,
        5,
    },
    // 衣
    {
        hanzi_8863,
        hanzi_8863_width,
        hanzi_8863_height,
        1,
        "yī",
        "clothing",
        WORDS_U8863,
        1,
    },
    // 服
    {
        hanzi_670D,
        hanzi_670D_width,
        hanzi_670D_height,
        1,
        "fú",
        "clothes; to serve",
        WORDS_U670D,
        2,
    },
    // 医
    {
        hanzi_533B,
        hanzi_533B_width,
        hanzi_533B_height,
        1,
        "yī",
        "medicine; doctor",
        WORDS_U533B,
        2,
    },
    // 院
    {
        hanzi_9662,
        hanzi_9662_width,
        hanzi_9662_height,
        1,
        "yuàn",
        "courtyard; institution",
        WORDS_U9662,
        1,
    },
    // 椅
    {
        hanzi_6905,
        hanzi_6905_width,
        hanzi_6905_height,
        1,
        "yǐ",
        "chair",
        WORDS_U6905,
        1,
    },
    // 月
    {
        hanzi_6708,
        hanzi_6708_width,
        hanzi_6708_height,
        1,
        "yuè",
        "month; moon",
        WORDS_U6708,
        1,
    },
    // 再
    {
        hanzi_518D,
        hanzi_518D_width,
        hanzi_518D_height,
        1,
        "zài",
        "again",
        WORDS_U518D,
        2,
    },
    // 怎
    {
        hanzi_600E,
        hanzi_600E_width,
        hanzi_600E_height,
        1,
        "zěn",
        "how",
        WORDS_U600E,
        2,
    },
    // 样
    {
        hanzi_6837,
        hanzi_6837_width,
        hanzi_6837_height,
        1,
        "yàng",
        "kind; appearance",
        WORDS_U6837,
        1,
    },
    // 这
    {
        hanzi_8FD9,
        hanzi_8FD9_width,
        hanzi_8FD9_height,
        1,
        "zhè",
        "this",
        WORDS_U8FD9,
        1,
    },
    // 中
    {
        hanzi_4E2D,
        hanzi_4E2D_width,
        hanzi_4E2D_height,
        1,
        "zhōng",
        "middle; China",
        WORDS_U4E2D,
        2,
    },
    // 国
    {
        hanzi_56FD,
        hanzi_56FD_width,
        hanzi_56FD_height,
        1,
        "guó",
        "country",
        WORDS_U56FD,
        1,
    },
    // 住
    {
        hanzi_4F4F,
        hanzi_4F4F_width,
        hanzi_4F4F_height,
        1,
        "zhù",
        "to live; to stay",
        WORDS_U4F4F,
        1,
    },
    // 桌
    {
        hanzi_684C,
        hanzi_684C_width,
        hanzi_684C_height,
        1,
        "zhuō",
        "table; desk",
        WORDS_U684C,
        1,
    },
    // 昨
    {
        hanzi_6628,
        hanzi_6628_width,
        hanzi_6628_height,
        1,
        "zuó",
        "yesterday",
        WORDS_U6628,
        1,
    },
    // 坐
    {
        hanzi_5750,
        hanzi_5750_width,
        hanzi_5750_height,
        1,
        "zuò",
        "to sit; to take (a bus)",
        WORDS_U5750,
        1,
    },
    // 做
    {
        hanzi_505A,
        hanzi_505A_width,
        hanzi_505A_height,
        1,
        "zuò",
        "to do; to make",
        WORDS_U505A,
        1,
    },
    // 吧
    {
        hanzi_5427,
        hanzi_5427_width,
        hanzi_5427_height,
        2,
        "ba",
        "particle: suggestion (let's)",
        WORDS_U5427,
        1,
    },
    // 白
    {
        hanzi_767D,
        hanzi_767D_width,
        hanzi_767D_height,
        2,
        "bái",
        "white",
        WORDS_U767D,
        1,
    },
    // 百
    {
        hanzi_767E,
        hanzi_767E_width,
        hanzi_767E_height,
        2,
        "bǎi",
        "hundred",
        WORDS_U767E,
        1,
    },
    // 帮
    {
        hanzi_5E2E,
        hanzi_5E2E_width,
        hanzi_5E2E_height,
        2,
        "bāng",
        "to help",
        WORDS_U5E2E,
        1,
    },
    // 助
    {
        hanzi_52A9,
        hanzi_52A9_width,
        hanzi_52A9_height,
        2,
        "zhù",
        "to assist",
        WORDS_U52A9,
        1,
    },
    // 报
    {
        hanzi_62A5,
        hanzi_62A5_width,
        hanzi_62A5_height,
        2,
        "bào",
        "newspaper; to report",
        WORDS_U62A5,
        1,
    },
    // 纸
    {
        hanzi_7EB8,
        hanzi_7EB8_width,
        hanzi_7EB8_height,
        2,
        "zhǐ",
        "paper",
        WORDS_U7EB8,
        1,
    },
    // 比
    {
        hanzi_6BD4,
        hanzi_6BD4_width,
        hanzi_6BD4_height,
        2,
        "bǐ",
        "to compare; than",
        WORDS_U6BD4,
        1,
    },
    // 别
    {
        hanzi_522B,
        hanzi_522B_width,
        hanzi_522B_height,
        2,
        "bié",
        "don't; other",
        WORDS_U522B,
        1,
    },
    // 宾
    {
        hanzi_5BBE,
        hanzi_5BBE_width,
        hanzi_5BBE_height,
        2,
        "bīn",
        "guest",
        WORDS_U5BBE,
        1,
    },
    // 馆
    {
        hanzi_9986,
        hanzi_9986_width,
        hanzi_9986_height,
        2,
        "guǎn",
        "hall; building",
        WORDS_U9986,
        1,
    },
    // 长
    {
        hanzi_957F,
        hanzi_957F_width,
        hanzi_957F_height,
        2,
        "cháng / zhǎng",
        "long; to grow",
        WORDS_U957F,
        1,
    },
    // 唱
    {
        hanzi_5531,
        hanzi_5531_width,
        hanzi_5531_height,
        2,
        "chàng",
        "to sing",
        WORDS_U5531,
        1,
    },
    // 歌
    {
        hanzi_6B4C,
        hanzi_6B4C_width,
        hanzi_6B4C_height,
        2,
        "gē",
        "song",
        WORDS_U6B4C,
        1,
    },
    // 穿
    {
        hanzi_7A7F,
        hanzi_7A7F_width,
        hanzi_7A7F_height,
        2,
        "chuān",
        "to wear; to pierce",
        WORDS_U7A7F,
        1,
    },
    // 次
    {
        hanzi_6B21,
        hanzi_6B21_width,
        hanzi_6B21_height,
        2,
        "cì",
        "time (occurrence); next",
        WORDS_U6B21,
        1,
    },
    // 从
    {
        hanzi_4ECE,
        hanzi_4ECE_width,
        hanzi_4ECE_height,
        2,
        "cóng",
        "from",
        WORDS_U4ECE,
        1,
    },
    // 错
    {
        hanzi_9519,
        hanzi_9519_width,
        hanzi_9519_height,
        2,
        "cuò",
        "wrong; mistake",
        WORDS_U9519,
        1,
    },
    // 篮
    {
        hanzi_7BEE,
        hanzi_7BEE_width,
        hanzi_7BEE_height,
        2,
        "lán",
        "basket",
        WORDS_U7BEE,
        1,
    },
    // 球
    {
        hanzi_7403,
        hanzi_7403_width,
        hanzi_7403_height,
        2,
        "qiú",
        "ball",
        WORDS_U7403,
        1,
    },
    // 到
    {
        hanzi_5230,
        hanzi_5230_width,
        hanzi_5230_height,
        2,
        "dào",
        "to arrive; to",
        WORDS_U5230,
        1,
    },
    // 得
    {
        hanzi_5F97,
        hanzi_5F97_width,
        hanzi_5F97_height,
        2,
        "de / dé / děi",
        "verb particle; to obtain; must",
        WORDS_U5F97,
        2,
    },
    // 等
    {
        hanzi_7B49,
        hanzi_7B49_width,
        hanzi_7B49_height,
        2,
        "děng",
        "to wait; etc.",
        WORDS_U7B49,
        1,
    },
    // 弟
    {
        hanzi_5F1F,
        hanzi_5F1F_width,
        hanzi_5F1F_height,
        2,
        "dì",
        "younger brother",
        WORDS_U5F1F,
        1,
    },
    // 第
    {
        hanzi_7B2C,
        hanzi_7B2C_width,
        hanzi_7B2C_height,
        2,
        "dì",
        "ordinal prefix (No.)",
        WORDS_U7B2C,
        1,
    },
    // 懂
    {
        hanzi_61C2,
        hanzi_61C2_width,
        hanzi_61C2_height,
        2,
        "dǒng",
        "to understand",
        WORDS_U61C2,
        1,
    },
    // 房
    {
        hanzi_623F,
        hanzi_623F_width,
        hanzi_623F_height,
        2,
        "fáng",
        "house; room",
        WORDS_U623F,
        1,
    },
    // 间
    {
        hanzi_95F4,
        hanzi_95F4_width,
        hanzi_95F4_height,
        2,
        "jiān",
        "room; between",
        WORDS_U95F4,
        2,
    },
    // 非
    {
        hanzi_975E,
        hanzi_975E_width,
        hanzi_975E_height,
        2,
        "fēi",
        "not; wrong",
        WORDS_U975E,
        1,
    },
    // 常
    {
        hanzi_5E38,
        hanzi_5E38_width,
        hanzi_5E38_height,
        2,
        "cháng",
        "often; ordinary",
        WORDS_U5E38,
        1,
    },
    // 务
    {
        hanzi_52A1,
        hanzi_52A1_width,
        hanzi_52A1_height,
        2,
        "wù",
        "affair; task",
        WORDS_U52A1,
        1,
    },
    // 员
    {
        hanzi_5458,
        hanzi_5458_width,
        hanzi_5458_height,
        2,
        "yuán",
        "member; staff",
        WORDS_U5458,
        1,
    },
    // 告
    {
        hanzi_544A,
        hanzi_544A_width,
        hanzi_544A_height,
        2,
        "gào",
        "to tell; to inform",
        WORDS_U544A,
        1,
    },
    // 诉
    {
        hanzi_8BC9,
        hanzi_8BC9_width,
        hanzi_8BC9_height,
        2,
        "sù",
        "to tell; to complain",
        WORDS_U8BC9,
        1,
    },
    // 哥
    {
        hanzi_54E5,
        hanzi_54E5_width,
        hanzi_54E5_height,
        2,
        "gē",
        "older brother",
        WORDS_U54E5,
        1,
    },
    // 给
    {
        hanzi_7ED9,
        hanzi_7ED9_width,
        hanzi_7ED9_height,
        2,
        "gěi",
        "to give; for",
        WORDS_U7ED9,
        1,
    },
    // 公
    {
        hanzi_516C,
        hanzi_516C_width,
        hanzi_516C_height,
        2,
        "gōng",
        "public; male (animal)",
        WORDS_U516C,
        2,
    },
    // 共
    {
        hanzi_5171,
        hanzi_5171_width,
        hanzi_5171_height,
        2,
        "gòng",
        "together; common",
        WORDS_U5171,
        1,
    },
    // 汽
    {
        hanzi_6C7D,
        hanzi_6C7D_width,
        hanzi_6C7D_height,
        2,
        "qì",
        "steam; vapor",
        WORDS_U6C7D,
        1,
    },
    // 司
    {
        hanzi_53F8,
        hanzi_53F8_width,
        hanzi_53F8_height,
        2,
        "sī",
        "to manage; department",
        WORDS_U53F8,
        1,
    },
    // 贵
    {
        hanzi_8D35,
        hanzi_8D35_width,
        hanzi_8D35_height,
        2,
        "guì",
        "expensive; noble",
        WORDS_U8D35,
        1,
    },
    // 过
    {
        hanzi_8FC7,
        hanzi_8FC7_width,
        hanzi_8FC7_height,
        2,
        "guò / guo",
        "to pass; particle: have done before",
        WORDS_U8FC7,
        1,
    },
    // 还
    {
        hanzi_8FD8,
        hanzi_8FD8_width,
        hanzi_8FD8_height,
        2,
        "hái / huán",
        "still; also; to return (a thing)",
        WORDS_U8FD8,
        1,
    },
    // 孩
    {
        hanzi_5B69,
        hanzi_5B69_width,
        hanzi_5B69_height,
        2,
        "hái",
        "child",
        WORDS_U5B69,
        1,
    },
    // 黑
    {
        hanzi_9ED1,
        hanzi_9ED1_width,
        hanzi_9ED1_height,
        2,
        "hēi",
        "black; dark",
        WORDS_U9ED1,
        1,
    },
    // 红
    {
        hanzi_7EA2,
        hanzi_7EA2_width,
        hanzi_7EA2_height,
        2,
        "hóng",
        "red",
        WORDS_U7EA2,
        1,
    },
    // 火
    {
        hanzi_706B,
        hanzi_706B_width,
        hanzi_706B_height,
        2,
        "huǒ",
        "fire",
        WORDS_U706B,
        1,
    },
    // 站
    {
        hanzi_7AD9,
        hanzi_7AD9_width,
        hanzi_7AD9_height,
        2,
        "zhàn",
        "to stand; station",
        WORDS_U7AD9,
        1,
    },
    // 场
    {
        hanzi_573A,
        hanzi_573A_width,
        hanzi_573A_height,
        2,
        "chǎng",
        "field; place",
        WORDS_U573A,
        1,
    },
    // 鸡
    {
        hanzi_9E21,
        hanzi_9E21_width,
        hanzi_9E21_height,
        2,
        "jī",
        "chicken",
        WORDS_U9E21,
        1,
    },
    // 蛋
    {
        hanzi_86CB,
        hanzi_86CB_width,
        hanzi_86CB_height,
        2,
        "dàn",
        "egg",
        WORDS_U86CB,
        1,
    },
    // 件
    {
        hanzi_4EF6,
        hanzi_4EF6_width,
        hanzi_4EF6_height,
        2,
        "jiàn",
        "measure word for clothes, matters",
        WORDS_U4EF6,
        1,
    },
    // 教
    {
        hanzi_6559,
        hanzi_6559_width,
        hanzi_6559_height,
        2,
        "jiào / jiāo",
        "to teach; teaching",
        WORDS_U6559,
        1,
    },
    // 室
    {
        hanzi_5BA4,
        hanzi_5BA4_width,
        hanzi_5BA4_height,
        2,
        "shì",
        "room",
        WORDS_U5BA4,
        1,
    },
    // 介
    {
        hanzi_4ECB,
        hanzi_4ECB_width,
        hanzi_4ECB_height,
        2,
        "jiè",
        "to be between; to introduce",
        WORDS_U4ECB,
        1,
    },
    // 绍
    {
        hanzi_7ECD,
        hanzi_7ECD_width,
        hanzi_7ECD_height,
        2,
        "shào",
        "to continue; used in 'introduce'",
        WORDS_U7ECD,
        1,
    },
    // 近
    {
        hanzi_8FD1,
        hanzi_8FD1_width,
        hanzi_8FD1_height,
        2,
        "jìn",
        "near",
        WORDS_U8FD1,
        1,
    },
    // 进
    {
        hanzi_8FDB,
        hanzi_8FDB_width,
        hanzi_8FDB_height,
        2,
        "jìn",
        "to enter",
        WORDS_U8FDB,
        1,
    },
    // 就
    {
        hanzi_5C31,
        hanzi_5C31_width,
        hanzi_5C31_height,
        2,
        "jiù",
        "just; then; right away",
        WORDS_U5C31,
        1,
    },
    // 咖
    {
        hanzi_5496,
        hanzi_5496_width,
        hanzi_5496_height,
        2,
        "kā",
        "used in 'coffee'",
        WORDS_U5496,
        1,
    },
    // 啡
    {
        hanzi_5561,
        hanzi_5561_width,
        hanzi_5561_height,
        2,
        "fēi",
        "used in 'coffee'",
        WORDS_U5561,
        1,
    },
    // 始
    {
        hanzi_59CB,
        hanzi_59CB_width,
        hanzi_59CB_height,
        2,
        "shǐ",
        "to begin",
        WORDS_U59CB,
        1,
    },
    // 考
    {
        hanzi_8003,
        hanzi_8003_width,
        hanzi_8003_height,
        2,
        "kǎo",
        "to test; to examine",
        WORDS_U8003,
        1,
    },
    // 试
    {
        hanzi_8BD5,
        hanzi_8BD5_width,
        hanzi_8BD5_height,
        2,
        "shì",
        "to try; test",
        WORDS_U8BD5,
        1,
    },
    // 可
    {
        hanzi_53EF,
        hanzi_53EF_width,
        hanzi_53EF_height,
        2,
        "kě",
        "can; may",
        WORDS_U53EF,
        2,
    },
    // 以
    {
        hanzi_4EE5,
        hanzi_4EE5_width,
        hanzi_4EE5_height,
        2,
        "yǐ",
        "by means of; to use",
        WORDS_U4EE5,
        2,
    },
    // 课
    {
        hanzi_8BFE,
        hanzi_8BFE_width,
        hanzi_8BFE_height,
        2,
        "kè",
        "class; lesson",
        WORDS_U8BFE,
        1,
    },
    // 快
    {
        hanzi_5FEB,
        hanzi_5FEB_width,
        hanzi_5FEB_height,
        2,
        "kuài",
        "fast; quick",
        WORDS_U5FEB,
        2,
    },
    // 乐
    {
        hanzi_4E50,
        hanzi_4E50_width,
        hanzi_4E50_height,
        2,
        "lè / yuè",
        "happy; music",
        WORDS_U4E50,
        1,
    },
    // 累
    {
        hanzi_7D2F,
        hanzi_7D2F_width,
        hanzi_7D2F_height,
        2,
        "lèi",
        "tired",
        WORDS_U7D2F,
        1,
    },
    // 离
    {
        hanzi_79BB,
        hanzi_79BB_width,
        hanzi_79BB_height,
        2,
        "lí",
        "away from; to leave",
        WORDS_U79BB,
        1,
    },
    // 两
    {
        hanzi_4E24,
        hanzi_4E24_width,
        hanzi_4E24_height,
        2,
        "liǎng",
        "two (of something)",
        WORDS_U4E24,
        1,
    },
    // 零
    {
        hanzi_96F6,
        hanzi_96F6_width,
        hanzi_96F6_height,
        2,
        "líng",
        "zero",
        WORDS_U96F6,
        1,
    },
    // 路
    {
        hanzi_8DEF,
        hanzi_8DEF_width,
        hanzi_8DEF_height,
        2,
        "lù",
        "road; way",
        WORDS_U8DEF,
        1,
    },
    // 旅
    {
        hanzi_65C5,
        hanzi_65C5_width,
        hanzi_65C5_height,
        2,
        "lǚ",
        "to travel",
        WORDS_U65C5,
        1,
    },
    // 游
    {
        hanzi_6E38,
        hanzi_6E38_width,
        hanzi_6E38_height,
        2,
        "yóu",
        "to swim; to tour",
        WORDS_U6E38,
        2,
    },
    // 卖
    {
        hanzi_5356,
        hanzi_5356_width,
        hanzi_5356_height,
        2,
        "mài",
        "to sell",
        WORDS_U5356,
        1,
    },
    // 慢
    {
        hanzi_6162,
        hanzi_6162_width,
        hanzi_6162_height,
        2,
        "màn",
        "slow",
        WORDS_U6162,
        1,
    },
    // 忙
    {
        hanzi_5FD9,
        hanzi_5FD9_width,
        hanzi_5FD9_height,
        2,
        "máng",
        "busy",
        WORDS_U5FD9,
        1,
    },
    // 每
    {
        hanzi_6BCF,
        hanzi_6BCF_width,
        hanzi_6BCF_height,
        2,
        "měi",
        "every; each",
        WORDS_U6BCF,
        1,
    },
    // 妹
    {
        hanzi_59B9,
        hanzi_59B9_width,
        hanzi_59B9_height,
        2,
        "mèi",
        "younger sister",
        WORDS_U59B9,
        1,
    },
    // 门
    {
        hanzi_95E8,
        hanzi_95E8_width,
        hanzi_95E8_height,
        2,
        "mén",
        "door; gate",
        WORDS_U95E8,
        1,
    },
    // 条
    {
        hanzi_6761,
        hanzi_6761_width,
        hanzi_6761_height,
        2,
        "tiáo",
        "strip; measure word for long things",
        WORDS_U6761,
        1,
    },
    // 男
    {
        hanzi_7537,
        hanzi_7537_width,
        hanzi_7537_height,
        2,
        "nán",
        "male; man",
        WORDS_U7537,
        1,
    },
    // 您
    {
        hanzi_60A8,
        hanzi_60A8_width,
        hanzi_60A8_height,
        2,
        "nín",
        "you (polite)",
        WORDS_U60A8,
        1,
    },
    // 牛
    {
        hanzi_725B,
        hanzi_725B_width,
        hanzi_725B_height,
        2,
        "niú",
        "cow; ox",
        WORDS_U725B,
        1,
    },
    // 奶
    {
        hanzi_5976,
        hanzi_5976_width,
        hanzi_5976_height,
        2,
        "nǎi",
        "milk; grandma",
        WORDS_U5976,
        1,
    },
    // 旁
    {
        hanzi_65C1,
        hanzi_65C1_width,
        hanzi_65C1_height,
        2,
        "páng",
        "side; beside",
        WORDS_U65C1,
        1,
    },
    // 边
    {
        hanzi_8FB9,
        hanzi_8FB9_width,
        hanzi_8FB9_height,
        2,
        "biān",
        "side; edge",
        WORDS_U8FB9,
        3,
    },
    // 跑
    {
        hanzi_8DD1,
        hanzi_8DD1_width,
        hanzi_8DD1_height,
        2,
        "pǎo",
        "to run",
        WORDS_U8DD1,
        1,
    },
    // 步
    {
        hanzi_6B65,
        hanzi_6B65_width,
        hanzi_6B65_height,
        2,
        "bù",
        "step; pace",
        WORDS_U6B65,
        1,
    },
    // 便
    {
        hanzi_4FBF,
        hanzi_4FBF_width,
        hanzi_4FBF_height,
        2,
        "pián / biàn",
        "used in 'cheap'; convenient",
        WORDS_U4FBF,
        1,
    },
    // 宜
    {
        hanzi_5B9C,
        hanzi_5B9C_width,
        hanzi_5B9C_height,
        2,
        "yí",
        "suitable",
        WORDS_U5B9C,
        1,
    },
    // 票
    {
        hanzi_7968,
        hanzi_7968_width,
        hanzi_7968_height,
        2,
        "piào",
        "ticket",
        WORDS_U7968,
        1,
    },
    // 妻
    {
        hanzi_59BB,
        hanzi_59BB_width,
        hanzi_59BB_height,
        2,
        "qī",
        "wife",
        WORDS_U59BB,
        1,
    },
    // 床
    {
        hanzi_5E8A,
        hanzi_5E8A_width,
        hanzi_5E8A_height,
        2,
        "chuáng",
        "bed",
        WORDS_U5E8A,
        1,
    },
    // 千
    {
        hanzi_5343,
        hanzi_5343_width,
        hanzi_5343_height,
        2,
        "qiān",
        "thousand",
        WORDS_U5343,
        1,
    },
    // 铅
    {
        hanzi_94C5,
        hanzi_94C5_width,
        hanzi_94C5_height,
        2,
        "qiān",
        "lead (metal)",
        WORDS_U94C5,
        1,
    },
    // 笔
    {
        hanzi_7B14,
        hanzi_7B14_width,
        hanzi_7B14_height,
        2,
        "bǐ",
        "pen; brush",
        WORDS_U7B14,
        1,
    },
    // 晴
    {
        hanzi_6674,
        hanzi_6674_width,
        hanzi_6674_height,
        2,
        "qíng",
        "sunny; clear",
        WORDS_U6674,
        1,
    },
    // 让
    {
        hanzi_8BA9,
        hanzi_8BA9_width,
        hanzi_8BA9_height,
        2,
        "ràng",
        "to let; to make",
        WORDS_U8BA9,
        1,
    },
    // 日
    {
        hanzi_65E5,
        hanzi_65E5_width,
        hanzi_65E5_height,
        2,
        "rì",
        "sun; day",
        WORDS_U65E5,
        2,
    },
    // 班
    {
        hanzi_73ED,
        hanzi_73ED_width,
        hanzi_73ED_height,
        2,
        "bān",
        "class; shift",
        WORDS_U73ED,
        1,
    },
    // 身
    {
        hanzi_8EAB,
        hanzi_8EAB_width,
        hanzi_8EAB_height,
        2,
        "shēn",
        "body",
        WORDS_U8EAB,
        1,
    },
    // 体
    {
        hanzi_4F53,
        hanzi_4F53_width,
        hanzi_4F53_height,
        2,
        "tǐ",
        "body; form",
        WORDS_U4F53,
        1,
    },
    // 病
    {
        hanzi_75C5,
        hanzi_75C5_width,
        hanzi_75C5_height,
        2,
        "bìng",
        "illness; sick",
        WORDS_U75C5,
        1,
    },
    // 事
    {
        hanzi_4E8B,
        hanzi_4E8B_width,
        hanzi_4E8B_height,
        2,
        "shì",
        "matter; thing; job",
        WORDS_U4E8B,
        1,
    },
    // 情
    {
        hanzi_60C5,
        hanzi_60C5_width,
        hanzi_60C5_height,
        2,
        "qíng",
        "feeling; situation",
        WORDS_U60C5,
        1,
    },
    // 手
    {
        hanzi_624B,
        hanzi_624B_width,
        hanzi_624B_height,
        2,
        "shǒu",
        "hand",
        WORDS_U624B,
        2,
    },
    // 表
    {
        hanzi_8868,
        hanzi_8868_width,
        hanzi_8868_height,
        2,
        "biǎo",
        "watch; chart; to show",
        WORDS_U8868,
        1,
    },
    // 送
    {
        hanzi_9001,
        hanzi_9001_width,
        hanzi_9001_height,
        2,
        "sòng",
        "to give (a gift); to see off",
        WORDS_U9001,
        1,
    },
    // 虽
    {
        hanzi_867D,
        hanzi_867D_width,
        hanzi_867D_height,
        2,
        "suī",
        "although",
        WORDS_U867D,
        1,
    },
    // 然
    {
        hanzi_7136,
        hanzi_7136_width,
        hanzi_7136_height,
        2,
        "rán",
        "so; like that",
        WORDS_U7136,
        1,
    },
    // 但
    {
        hanzi_4F46,
        hanzi_4F46_width,
        hanzi_4F46_height,
        2,
        "dàn",
        "but",
        WORDS_U4F46,
        1,
    },
    // 它
    {
        hanzi_5B83,
        hanzi_5B83_width,
        hanzi_5B83_height,
        2,
        "tā",
        "it",
        WORDS_U5B83,
        1,
    },
    // 踢
    {
        hanzi_8E22,
        hanzi_8E22_width,
        hanzi_8E22_height,
        2,
        "tī",
        "to kick",
        WORDS_U8E22,
        1,
    },
    // 题
    {
        hanzi_9898,
        hanzi_9898_width,
        hanzi_9898_height,
        2,
        "tí",
        "topic; question",
        WORDS_U9898,
        2,
    },
    // 跳
    {
        hanzi_8DF3,
        hanzi_8DF3_width,
        hanzi_8DF3_height,
        2,
        "tiào",
        "to jump",
        WORDS_U8DF3,
        1,
    },
    // 舞
    {
        hanzi_821E,
        hanzi_821E_width,
        hanzi_821E_height,
        2,
        "wǔ",
        "dance",
        WORDS_U821E,
        1,
    },
    // 外
    {
        hanzi_5916,
        hanzi_5916_width,
        hanzi_5916_height,
        2,
        "wài",
        "outside",
        WORDS_U5916,
        1,
    },
    // 完
    {
        hanzi_5B8C,
        hanzi_5B8C_width,
        hanzi_5B8C_height,
        2,
        "wán",
        "to finish",
        WORDS_U5B8C,
        1,
    },
    // 玩
    {
        hanzi_73A9,
        hanzi_73A9_width,
        hanzi_73A9_height,
        2,
        "wán",
        "to play; to have fun",
        WORDS_U73A9,
        1,
    },
    // 晚
    {
        hanzi_665A,
        hanzi_665A_width,
        hanzi_665A_height,
        2,
        "wǎn",
        "evening; late",
        WORDS_U665A,
        1,
    },
    // 往
    {
        hanzi_5F80,
        hanzi_5F80_width,
        hanzi_5F80_height,
        2,
        "wǎng",
        "toward",
        WORDS_U5F80,
        1,
    },
    // 为
    {
        hanzi_4E3A,
        hanzi_4E3A_width,
        hanzi_4E3A_height,
        2,
        "wèi / wéi",
        "for; because of; to act as",
        WORDS_U4E3A,
        2,
    },
    // 问
    {
        hanzi_95EE,
        hanzi_95EE_width,
        hanzi_95EE_height,
        2,
        "wèn",
        "to ask",
        WORDS_U95EE,
        2,
    },
    // 瓜
    {
        hanzi_74DC,
        hanzi_74DC_width,
        hanzi_74DC_height,
        2,
        "guā",
        "melon",
        WORDS_U74DC,
        1,
    },
    // 希
    {
        hanzi_5E0C,
        hanzi_5E0C_width,
        hanzi_5E0C_height,
        2,
        "xī",
        "to hope",
        WORDS_U5E0C,
        1,
    },
    // 望
    {
        hanzi_671B,
        hanzi_671B_width,
        hanzi_671B_height,
        2,
        "wàng",
        "to look at; to hope",
        WORDS_U671B,
        1,
    },
    // 洗
    {
        hanzi_6D17,
        hanzi_6D17_width,
        hanzi_6D17_height,
        2,
        "xǐ",
        "to wash",
        WORDS_U6D17,
        1,
    },
    // 笑
    {
        hanzi_7B11,
        hanzi_7B11_width,
        hanzi_7B11_height,
        2,
        "xiào",
        "to laugh; to smile",
        WORDS_U7B11,
        1,
    },
    // 新
    {
        hanzi_65B0,
        hanzi_65B0_width,
        hanzi_65B0_height,
        2,
        "xīn",
        "new",
        WORDS_U65B0,
        1,
    },
    // 姓
    {
        hanzi_59D3,
        hanzi_59D3_width,
        hanzi_59D3_height,
        2,
        "xìng",
        "surname",
        WORDS_U59D3,
        1,
    },
    // 休
    {
        hanzi_4F11,
        hanzi_4F11_width,
        hanzi_4F11_height,
        2,
        "xiū",
        "to rest",
        WORDS_U4F11,
        1,
    },
    // 息
    {
        hanzi_606F,
        hanzi_606F_width,
        hanzi_606F_height,
        2,
        "xī",
        "breath; to rest",
        WORDS_U606F,
        1,
    },
    // 雪
    {
        hanzi_96EA,
        hanzi_96EA_width,
        hanzi_96EA_height,
        2,
        "xuě",
        "snow",
        WORDS_U96EA,
        1,
    },
    // 颜
    {
        hanzi_989C,
        hanzi_989C_width,
        hanzi_989C_height,
        2,
        "yán",
        "color; face",
        WORDS_U989C,
        1,
    },
    // 色
    {
        hanzi_8272,
        hanzi_8272_width,
        hanzi_8272_height,
        2,
        "sè",
        "color",
        WORDS_U8272,
        1,
    },
    // 眼
    {
        hanzi_773C,
        hanzi_773C_width,
        hanzi_773C_height,
        2,
        "yǎn",
        "eye",
        WORDS_U773C,
        1,
    },
    // 睛
    {
        hanzi_775B,
        hanzi_775B_width,
        hanzi_775B_height,
        2,
        "jīng",
        "eyeball",
        WORDS_U775B,
        1,
    },
    // 羊
    {
        hanzi_7F8A,
        hanzi_7F8A_width,
        hanzi_7F8A_height,
        2,
        "yáng",
        "sheep; goat",
        WORDS_U7F8A,
        1,
    },
    // 肉
    {
        hanzi_8089,
        hanzi_8089_width,
        hanzi_8089_height,
        2,
        "ròu",
        "meat",
        WORDS_U8089,
        1,
    },
    // 要
    {
        hanzi_8981,
        hanzi_8981_width,
        hanzi_8981_height,
        2,
        "yào",
        "to want; will; must",
        WORDS_U8981,
        1,
    },
    // 药
    {
        hanzi_836F,
        hanzi_836F_width,
        hanzi_836F_height,
        2,
        "yào",
        "medicine",
        WORDS_U836F,
        1,
    },
    // 也
    {
        hanzi_4E5F,
        hanzi_4E5F_width,
        hanzi_4E5F_height,
        2,
        "yě",
        "also",
        WORDS_U4E5F,
        1,
    },
    // 已
    {
        hanzi_5DF2,
        hanzi_5DF2_width,
        hanzi_5DF2_height,
        2,
        "yǐ",
        "already",
        WORDS_U5DF2,
        1,
    },
    // 经
    {
        hanzi_7ECF,
        hanzi_7ECF_width,
        hanzi_7ECF_height,
        2,
        "jīng",
        "to pass through; classic",
        WORDS_U7ECF,
        1,
    },
    // 意
    {
        hanzi_610F,
        hanzi_610F_width,
        hanzi_610F_height,
        2,
        "yì",
        "meaning; idea",
        WORDS_U610F,
        1,
    },
    // 思
    {
        hanzi_601D,
        hanzi_601D_width,
        hanzi_601D_height,
        2,
        "sī",
        "to think",
        WORDS_U601D,
        1,
    },
    // 阴
    {
        hanzi_9634,
        hanzi_9634_width,
        hanzi_9634_height,
        2,
        "yīn",
        "cloudy; shade",
        WORDS_U9634,
        1,
    },
    // 因
    {
        hanzi_56E0,
        hanzi_56E0_width,
        hanzi_56E0_height,
        2,
        "yīn",
        "cause; because",
        WORDS_U56E0,
        1,
    },
    // 所
    {
        hanzi_6240,
        hanzi_6240_width,
        hanzi_6240_height,
        2,
        "suǒ",
        "place; so",
        WORDS_U6240,
        1,
    },
    // 泳
    {
        hanzi_6CF3,
        hanzi_6CF3_width,
        hanzi_6CF3_height,
        2,
        "yǒng",
        "to swim",
        WORDS_U6CF3,
        1,
    },
    // 右
    {
        hanzi_53F3,
        hanzi_53F3_width,
        hanzi_53F3_height,
        2,
        "yòu",
        "right (side)",
        WORDS_U53F3,
        1,
    },
    // 鱼
    {
        hanzi_9C7C,
        hanzi_9C7C_width,
        hanzi_9C7C_height,
        2,
        "yú",
        "fish",
        WORDS_U9C7C,
        1,
    },
    // 远
    {
        hanzi_8FDC,
        hanzi_8FDC_width,
        hanzi_8FDC_height,
        2,
        "yuǎn",
        "far",
        WORDS_U8FDC,
        1,
    },
    // 运
    {
        hanzi_8FD0,
        hanzi_8FD0_width,
        hanzi_8FD0_height,
        2,
        "yùn",
        "to move; luck",
        WORDS_U8FD0,
        1,
    },
    // 动
    {
        hanzi_52A8,
        hanzi_52A8_width,
        hanzi_52A8_height,
        2,
        "dòng",
        "to move",
        WORDS_U52A8,
        1,
    },
    // 早
    {
        hanzi_65E9,
        hanzi_65E9_width,
        hanzi_65E9_height,
        2,
        "zǎo",
        "early; morning",
        WORDS_U65E9,
        1,
    },
    // 丈
    {
        hanzi_4E08,
        hanzi_4E08_width,
        hanzi_4E08_height,
        2,
        "zhàng",
        "used in 'husband'; old length unit",
        WORDS_U4E08,
        1,
    },
    // 夫
    {
        hanzi_592B,
        hanzi_592B_width,
        hanzi_592B_height,
        2,
        "fū",
        "man; husband",
        WORDS_U592B,
        1,
    },
    // 找
    {
        hanzi_627E,
        hanzi_627E_width,
        hanzi_627E_height,
        2,
        "zhǎo",
        "to look for",
        WORDS_U627E,
        1,
    },
    // 着
    {
        hanzi_7740,
        hanzi_7740_width,
        hanzi_7740_height,
        2,
        "zhe",
        "particle: ongoing state",
        WORDS_U7740,
        1,
    },
    // 真
    {
        hanzi_771F,
        hanzi_771F_width,
        hanzi_771F_height,
        2,
        "zhēn",
        "really; true",
        WORDS_U771F,
        1,
    },
    // 正
    {
        hanzi_6B63,
        hanzi_6B63_width,
        hanzi_6B63_height,
        2,
        "zhèng",
        "just (now); straight; correct",
        WORDS_U6B63,
        1,
    },
    // 只
    {
        hanzi_53EA,
        hanzi_53EA_width,
        hanzi_53EA_height,
        2,
        "zhī / zhǐ",
        "measure word for animals; only",
        WORDS_U53EA,
        1,
    },
    // 知
    {
        hanzi_77E5,
        hanzi_77E5_width,
        hanzi_77E5_height,
        2,
        "zhī",
        "to know",
        WORDS_U77E5,
        1,
    },
    // 道
    {
        hanzi_9053,
        hanzi_9053_width,
        hanzi_9053_height,
        2,
        "dào",
        "road; way; to say",
        WORDS_U9053,
        1,
    },
    // 准
    {
        hanzi_51C6,
        hanzi_51C6_width,
        hanzi_51C6_height,
        2,
        "zhǔn",
        "accurate; to allow",
        WORDS_U51C6,
        1,
    },
    // 备
    {
        hanzi_5907,
        hanzi_5907_width,
        hanzi_5907_height,
        2,
        "bèi",
        "to prepare",
        WORDS_U5907,
        1,
    },
    // 走
    {
        hanzi_8D70,
        hanzi_8D70_width,
        hanzi_8D70_height,
        2,
        "zǒu",
        "to walk; to leave",
        WORDS_U8D70,
        1,
    },
    // 最
    {
        hanzi_6700,
        hanzi_6700_width,
        hanzi_6700_height,
        2,
        "zuì",
        "most",
        WORDS_U6700,
        1,
    },
    // 左
    {
        hanzi_5DE6,
        hanzi_5DE6_width,
        hanzi_5DE6_height,
        2,
        "zuǒ",
        "left (side)",
        WORDS_U5DE6,
        1,
    },
};

constexpr uint16_t CARD_COUNT =
    sizeof(CARDS) / sizeof(CARDS[0]);

constexpr uint8_t HISTORY_SIZE = 10;
Preferences preferences;
uint16_t recentHistory[HISTORY_SIZE];
uint8_t historyCount = 0;

bool isRecent(uint16_t index)
{
    for (uint8_t i = 0; i < historyCount; ++i)
        if (recentHistory[i] == index) return true;
    return false;
}

void rememberCard(uint16_t index)
{
    if (historyCount < HISTORY_SIZE)
        recentHistory[historyCount++] = index;
    else
    {
        for (uint8_t i = 1; i < HISTORY_SIZE; ++i)
            recentHistory[i - 1] = recentHistory[i];
        recentHistory[HISTORY_SIZE - 1] = index;
    }
    preferences.putUChar("histCount", historyCount);
    preferences.putBytes("history", recentHistory, historyCount * sizeof(uint16_t));
}
}

void Database::begin()
{
    randomSeed(esp_random());
    preferences.begin("koyeti-hsk", false);
    historyCount = preferences.getUChar("histCount", 0);
    if (historyCount > HISTORY_SIZE) historyCount = 0;
    const size_t expected = historyCount * sizeof(uint16_t);
    if (expected > 0 && preferences.getBytesLength("history") == expected)
        preferences.getBytes("history", recentHistory, expected);
    else if (expected > 0)
        historyCount = 0;
    for (uint8_t i = 0; i < historyCount; ++i)
        if (recentHistory[i] >= CARD_COUNT) { historyCount = 0; break; }
}

uint16_t Database::count() const
{
    return CARD_COUNT;
}

uint16_t Database::randomIndex(uint16_t avoidIndex)
{
    if (CARD_COUNT <= 1) return 0;
    uint16_t result;
    uint16_t attempts = 0;
    do
    {
        result = static_cast<uint16_t>(esp_random() % CARD_COUNT);
        ++attempts;
    }
    while ((result == avoidIndex || isRecent(result)) && attempts < 1000);
    if (result == avoidIndex || isRecent(result))
    {
        for (uint16_t i = 0; i < CARD_COUNT; ++i)
        {
            if (i != avoidIndex && !isRecent(i))
            {
                result = i;
                break;
            }
        }
    }
    rememberCard(result);
    return result;
}

const HanziCard& Database::card(uint16_t index) const
{
    return CARDS[index % CARD_COUNT];
}
