// Automatically generated header file
// Date: 2024-06-09 23:16:56.493801
// Quantized model exported from opt_Cosine_lr0.001_Aug_BitMnist_PerTensor_4bitsym_RMS_width64_32_16_bs128_epochs60.pth
// Generated by exportquant.py

#include <stdint.h>

#ifndef BITNETMCU_MODEL_H
#define BITNETMCU_MODEL_H

// Number of layers
#define NUM_LAYERS 4

// Maximum number of activations per layer
#define MAX_N_ACTIVATIONS 64

// Layer: L1
// QuantType: 4bitsym
#define L1_active
#define L1_bitperweight 4
#define L1_incoming_weights 256
#define L1_outgoing_weights 64
const uint32_t L1_weights[] = {
	0x11109900,0x90818010,0x00900019,0x99088011,0x0819a009,0x08110080,0x11018018,0x0a010098,
	0x0889a098,0x1b12110a,0x100088a1,0x8f54019a,0x01008092,0xdf65109a,0x10108882,0xfb72108a,
	0x10181109,0xe4608999,0x1088088c,0x95201880,0x08180aba,0x23018980,0x00989a81,0x01901211,
	0x89900122,0x99a01318,0x08988088,0x90bb8211,0x88898013,0x819aa091,0x00812110,0x088a9908,
	0x31322211,0x02021131,0x13211101,0x11011222,0x11098801,0x1888a812,0x10188080,0x82080002,
	0x10101008,0x898088a1,0x11100110,0x88089888,0x20008820,0x89a8a099,0x10988810,0x0a9880a8,
	0x29b98009,0x88108211,0x22889998,0x99001120,0x42118a99,0x00000111,0x42422233,0x44532890,
	0x21235652,0x20a89ca0,0x8889a9be,0xfffffc91,0x18beffff,0xffffc801,0x3089ddfe,0xeca91022,
	0x88880333,0x19aabb90,0x81002477,0x7389cba8,0x00991126,0x76419cba,0x8a9899b9,0x26728bca,
	0x08babbaa,0x057618ab,0x9bc9aa8c,0xb83648bb,0x0a98011a,0xbaa2329b,0x0089880b,0xaa1111ba,
	0x11809980,0x808009a9,0x11889100,0x88089a98,0x01080100,0x88998088,0x11101008,0x88a99808,
	0x10800001,0x00080080,0x80089890,0x98180080,0x01218000,0x0aa11108,0x00088808,0x82111880,
	0x88a99089,0x898899a8,0x9a808899,0x89010899,0x98008089,0x8000100a,0xa8820911,0x10120021,
	0x9a80ba01,0x12120119,0x89099888,0x88323231,0x98108889,0xac845551,0x0822889a,0xafd34643,
	0x09000190,0x9ff22553,0x9aa980b1,0x8ff63252,0x88a9ba80,0xbf064322,0x98808898,0x98533008,
	0x8918aaa9,0x92282100,0x9a89b990,0x11121199,0xa9988110,0x2218888a,0xaa9a9981,0x208a8998,
	0x988899a9,0xaa999889,0x98a88988,0x098089a8,0xaa988120,0x899ab9a8,0x9999a901,0x288aca99,
	0x990a8912,0x29b99a99,0x89901109,0x9a89808a,0x98b199a8,0x990a889a,0x99a90999,0x0089aa89,
	0x88988899,0x000aa980,0x9019a080,0x88190812,0x8108099a,0xe0109911,0x11102099,0xc0233143,
	0x12422436,0x76464441,0x82546565,0x54335540,0x00032382,0x12131119,0x9088abdc,0xb9800889,
	0x01118100,0x01001111,0x0000189a,0x01100000,0x2008a9c9,0x81108901,0x080aaa09,0xa8999810,
	0x08098889,0x80019189,0x089900a9,0x88888199,0x212a902a,0xc8918908,0x0310010c,0xb8880a21,
	0x82232aef,0x199a9112,0x8a03cff9,0x41000221,0xaadeffe7,0x52232911,0x8dfffe34,0x53111234,
	0x0bdba122,0x65512444,0x00880812,0x24545661,0x10111881,0x21223442,0x00811080,0x80080111,
	0x98808a9a,0x98999988,0x98a9aa89,0x98009999,0x989988aa,0x9908908a,0x809b810a,0xa9910209,
	0x8a8a9808,0x9898890a,0x8900990b,0xa9099a8a,0x888208aa,0xa899980a,0x999a8880,0x89a9989b,
	0x809b99ab,0x89babdac,0x12228eff,0xdeddec9a,0x04555510,0x80982010,0x02236777,0x67765521,
	0x02022222,0x34645740,0x80110001,0x00247650,0x80118901,0x08801201,0x00899000,0x98808880,
	0x11010111,0x12123110,0x01121004,0x01101112,0x01220113,0x20020222,0x13320112,0x22211232,
	0x22088042,0x23210211,0x11009103,0x32112023,0x11000118,0x09101410,0x1809a089,0xabb99aa9,
	0x08001888,0x99918fca,0x19009912,0x0119efc8,0x808a8001,0x018fff98,0x800999a8,0x89effca8,
	0x21108908,0x8cfff981,0x02098908,0x1fffb900,0x18980081,0x1efea001,0x00900122,0x8ceb8812,
	0x18009aa9,0x98020100,0x10188981,0x09080080,0x00220a80,0x00811908,0x00120288,0x90801801,
	0x00890881,0x01919a91,0x80900808,0x80111800,0x08810119,0x80209001,0x08110189,0x80018008,
	0x09209980,0x18008100,0x8809a803,0x9a110990,0x9cac8042,0xfb430998,0x9baa8159,0xff230890,
	0x8000335d,0xff264191,0x0113323f,0xff845100,0x0134330f,0xffa33011,0x011110af,0xff822081,
	0x081809a9,0xa9990000,0x1111099a,0xbaa99811,0x01201811,0x9a889008,0x2134439a,0xa8908108,
	0x02573564,0x19890098,0x00312322,0x28000991,0x9effffff,0xa0088800,0xafffffd1,0x12000110,
	0xaffc0232,0x20181000,0x99144200,0x00081201,0x1343309a,0x90089808,0x23322008,0x00011188,
	0x22280800,0x18000189,0x12200989,0x99988909,0x2108808a,0x88aa8988,0x01088088,0x88898901,
	0x81000009,0xb9223108,0x081200af,0xfd462000,0x8002418f,0xfc771990,0x0123530f,0xf074adba,
	0x0081152f,0xf449cfa0,0x8809845f,0xf61bc810,0x8a90925c,0xa28b0223,0x89988009,0x81813131,
	0x00898908,0x00019880,0x80801888,0x09080880,0x81800800,0x00880108,0x80890888,0x00210199,
	0x80122888,0x08080180,0x808a8000,0x88880890,0x00080102,0x081a8880,0x00808008,0x08918180,
	0x18023008,0x88880801,0x01020108,0x0880a811,0x01001110,0x11810088,0x18890000,0x88018090,
	0x19818898,0x88889880,0x8ab12230,0x90801211,0x8bde0354,0x11099081,0x0aefffb6,0x30008800,
	0x228effff,0x88001820,0x24764bcd,0xb9898188,0x11347771,0x09889808,0x08b80081,0x08109899,
	0x898aa991,0x88199898,0x08098811,0x200a9880,0x08022108,0x80899900,0x11208888,0x08080080,
	0x01111121,0x20010110,0x21010100,0x88998811,0x11108cdd,0xfff98100,0x1130809a,0x999aaa80,
	0x01288113,0x44388998,0x08098134,0x01088992,0x2090108c,0xba829080,0x00914098,0x4211b888,
	0x21b9ba81,0x18889081,0x00018821,0x9b99c111,0x10933453,0xaa989000,0x1adcfffd,0xb8181001,
	0x08bfffff,0x01181000,0x2089ca03,0x29a90880,0x21356775,0x89098902,0x02344208,0x88988001,
	0x111218ad,0xb8021110,0x223309ff,0xc2211102,0x13348fff,0x12301801,0x2443effd,0x53101890,
	0x3343fff2,0x51088980,0x1120ffc5,0x58989880,0x1000b936,0x1a891800,0x18a00022,0xa9982080,
	0x09881029,0x98080010,0x10011889,0x80000100,0x891800a0,0x18810080,0x18108018,0x88898888,
	0x89908880,0x88890000,0x08801009,0x08080880,0x10889010,0x18888011,0x10001880,0x08088012,
	0x18098a99,0x80801000,0x8099bba8,0x98882808,0x188aaa9a,0x90880088,0x81098880,0x9a001088,
	0x01111080,0x90109998,0x01210099,0x90018990,0x23010a00,0x08088a80,0x24138a98,0x00018990,
	0x2444428a,0x88089810,0x01367775,0x20008210,0x08913454,0x21122081,0x9abbcdda,0x90099900,
	0x88bcfdbc,0x98ab8901,0x0ab98a80,0x9808a901,0x88801880,0x0028b901,0x88118001,0x21199888,
	0x10180898,0x08900000,0x08180801,0x00900080,0x80800112,0x20080290,0x00001332,0x10280210,
	0x81311080,0x12110080,0x00001021,0x12312338,0x9aa89999,0x08902200,0x9cffffff,0xfdcdbaa8,
	0xacffffff,0xdedeccba,0x89013231,0x18ab9cca,0x13224121,0x10008899,0x23320101,0x03111080,
	0x02428100,0x82133332,0x00019011,0xa8102121,0x10998039,0x809a0011,0x0889a888,0x8b990800,
	0x33000001,0x02310022,0x31100118,0x80210101,0x12118801,0x88913102,0x22109a01,0x18880891,
	0x13000982,0x1200aaa9,0x21200088,0x218abab8,0x21801a0d,0x231d89a8,0x1081091d,0x370ea808,
	0x1101812c,0x460d9001,0x00122309,0x54da1301,0x014209d1,0x6ad13000,0x12289d01,0x1af98981,
	0x119b9021,0x21b98990,0x29ddb101,0x21c09a80,0x08b98810,0x31010801,0x10098013,0x52100120,
	0x44333210,0x13322323,0x22231899,0x90211212,0x34218a18,0x80219911,0x321089a9,0x10208a82,
	0x41112341,0x31019a80,0x22455309,0x2188a980,0x280efff1,0x50989880,0x1aefff47,0x10211890,
	0x29bf2763,0x81281002,0x11984211,0x99898212,0x22cdda88,0x89980082,0x2399b982,0x31181b91,
	0x32142880,0x01188901,0x31880100,0x008a9802,0x2208a008,0x00090221,0x42210008,0x08881123,
	0x00909988,0x98880100,0x80000088,0x98000810,0x00113120,0x01888181,0x00223343,0x10011118,
	0x90101988,0x00089080,0x09bcffec,0xb98009aa,0x09990131,0x1098899a,0x00277743,0x09800888,
	0x8ab91899,0xc9988820,0xaefffffb,0x80881011,0x8cfffc81,0x20100810,0x81803342,0x00809100,
	0x12754188,0x8a010008,0x81180010,0x109a8018,0x08890901,0x98110181,0x80800112,0x12118880,
	0x08800009,0x08102010,0x80000801,0x88021181,0x00088810,0x00100088,0x10001180,0x02112280,
	0x01801212,0x00100111,0x80111120,0x80088988,0x11322081,0x22110891,0x08354802,0x42234218,
	0x0ab83356,0x33231418,0x8cffffbd,0xa99ba001,0x9cffffff,0xfeffca81,0x011209aa,0xbddaaa90,
	0x02322301,0x99a8aaa8,0x81280a99,0x88189891,0x08898a08,0x02080a90,0x8098a800,0x09980881,
	0x80808acc,0xcaa88980,0x1111119b,0xbca9a890,0x81335453,0x8ba9a989,0x10446777,0x74808898,
	0x01211354,0x41090a90,0x90808bff,0xe920bc80,0x098099b9,0x9210a911,0x88ab8808,0x90828108,
	0x00080089,0x89000111,0x00189898,0x88988818,0x00089801,0xa090b911,0x09918019,0x81809981,
	0x809aa900,0x00889008,0x80881909,0x09100809,0x0000010a,0x80822009,0x88980881,0x28008808,
	0xbaaaaaab,0xbaaaab9a,0xabbbabb8,0x989ab99b,0xabaa8988,0x98880aaa,0xba0018a8,0x9a818009,
	0xbb832088,0x01080808,0xba999990,0x99180810,0x90089811,0x10000118,0x90821128,0xa8113288,
	0xa001001a,0x80001810,0xb811899d,0xa89ad910,0x8008101b,0xbcca9340,0x9180189d,0xdaa01540,
	0x02113029,0x01136529,0x92356774,0x65566589,0x91244677,0x755528bb,0xa9101022,0x33318aac,
	0x00008888,0x98011000,0x10080a89,0x80111210,0x80109890,0x12122221,0x01108b90,0x18082311,
	0x00889a98,0x09881810,0x1080abb0,0x8a121102,0x18810991,0x88009901,0x18898001,0xa9a99b91,
	0x11110218,0x88899082,0x31233219,0x01821033,0x21211220,0x90213222,0x18021221,0x11234220,
	0x0aa01022,0x25233280,0x0a9a0221,0x21228aa9,0x89bfedff,0xfffeda88,0x088aefff,0xfffeba01,
	0x02011809,0x81800008,0x01088889,0x80010011,0x11210021,0x00118118,0x00101181,0x0a980800,
	0x11019882,0x22100189,0x1119a18a,0x810a8180,0x122241be,0xb0a88899,0x11458fc8,0x09180880,
	0x989fff93,0x19101811,0x9afffa74,0xa9112021,0x89cd9351,0xc9080021,0x8bc99243,0xbbb98880,
	0x88998116,0x2ddb8a99,0x80998015,0x329aaa88,0x00021021,0x54088101,0x10088990,0x13421111,
	0x88089900,0x11221081,0x98880023,0x22345310,0x09918100,0x24765308,0x00010811,0x12ffffda,
	0x8810001b,0xefffffdc,0x88200088,0x88911188,0x98199a81,0x23677776,0x88108880,0x99b05666,
	0x89898011,0x899bbb12,0x98811898,0x89109b98,0x89080889,0x888998aa,0x80800890,0x211008b9,
	0x89900011,0x800019a8,0x9999a000,0x00889ba9,0x98998898,0x80908988,0x98919001,0x80801088,
	0x00880442,0x09100090,0x99814658,0xa0118990,0x8a81673b,0xc21b9800,0x9ab3771e,0x82880899,
	0x9a9377ff,0x30981088,0x888277fc,0x49901801,0x889833f9,0x48888810,0x08a912d8,0x28909808,
	0x810880b1,0x19101199,0x01000881,0x18001199,0x88180800,0x81081988,0x09888980,0x80908998,
	0x80989a18,0x09888080,0x08990900,0x88800998,0x909aa000,0x018a2208,0x890a9908,0x88889909,
	0x00000008,0xaba88010,0x0101199d,0xfd981001,0x123189ff,0xfab18100,0x00118eff,0xf9930001,
	0x12318fff,0xf2130203,0x08219fff,0xa4018102,0x18129ffc,0x61809883,0x08908eb4,0x381a9881,
	0x88a90810,0x009a9011,0x0a902081,0x98980111,0x08191008,0x90980111,0x00080210,0x81890000,
	0x10010002,0x11188281,0x18000100,0x81080110,0x01190280,0x01121100,0x18010820,0x02008800,
	0x11010222,0x310b9012,0x11188882,0x239dea82,0x21999988,0x359cfd90,0x00001908,0x578fff12,
	0x181898aa,0x679ffc13,0x298098aa,0x77aff043,0x18889009,0x63efa652,0x1800010b,0x28ca4533,
	0x180098a0,0x1a925120,0x11000189,0x89228880,0x000001a1,0x80080888,0x10800990,0x90889890,
	0x10009188,0x98801801,0x80008909,0x89881808,0x10100901,0x09998002,0x11108880,0x20088800,
	0x00890988,0x80808088,0x80000889,0xaa980800,0x88809aac,0xedca8988,0x80000bff,0xfed9bb09,
	0x990139ac,0xadfaca88,0x98080109,0xabb913c8,0x8998829a,0x880232a9,0x08008888,0x19142118,
	0x08999c91,0x8f943218,0x23199910,0xffa24320,0x211aa90f,0xff225528,0x0280109f,0xf1223300,
	0x10109000,0x12231110,0x08018989,0x05518000,0x81211109,0x05231001,0x10810110,0x14212280,
	0x22108809,0x98800212,0x20099988,0x88001022,0x018bd981,0x00114201,0x18bfc010,0x02343212,
	0x09ed0132,0x34431212,0x08dd8034,0x2befb881,0x19bba223,0x198c9b99,0x10ba8a02,0xad882089,
	0x8888a801,0xac990111,0x0100aa03,0x8ca88020,0x10008902,0x8aa98911,0x2809a924,0x21288811,
	0x00098100,0x13342111,0x1220a900,0x11310202,0x120899a1,0x08208111,0x12018809,0x90091101,
	0x88a89808,0x89990989,0x0999a011,0x90810888,0x09cba439,0x99110980,0x99dd358b,0x9809c880,
	0x8bea242d,0x80980808,0x8adb054a,0xaca11081,0x9ce9016a,0xbd800a91,0xa9c99160,0xa9a89914,
	0x9900a14a,0xc0094233,0x9819233a,0xd0888002,0x9008045a,0xb809a911,0x01193458,0x88988011,
	0x82088141,0x80081020,0x00121122,0x11989009,0x91233221,0x21809800,0x88880012,0x43318888,
	0x00182311,0x11328098,0x90044521,0x12342089,0x81246321,0x01210900,0x81043253,0x23222800,
	0x8a911108,0x22341a08,0xadfdcffa,0x03408890,0x9efffd12,0x23098aa9,0x09884542,0x20ba9aba,
	0x14756429,0xabebbb00,0x333221bc,0xdb990111,0x13210aca,0xa9003231,0x1808aaa8,0x88098888,
	0x88899998,0xcb88bb99,0x880a0198,0x89c9baa9,0x00080091,0x99aaa999,0x089aaba8,0x18998898,
	0x21123120,0x32202131,0x0111219a,0x01088201,0x111828a9,0x13980002,0x08881019,0x11881111,
	0x10998088,0x22118223,0x00a0899e,0xa0333322,0x888888cf,0xda023322,0x19a9dffc,0x58be9801,
	0x1abbbc92,0x619dffb0,0x8abbc824,0x7309afc8,0x00acacb9,0x23243fd8,0x103209ed,0xa8143dc0,
	0x11332031,0x01222c91,0x08000810,0x23989991,0x019ab888,0x9199b880,0x22188989,0x19898113,
	0xb9abbb8a,0x988a9989,0xbaa99999,0x0890800a,0xb9889810,0x88880808,0xaa890990,0x80800118,
	0x80881111,0x10180200,0x81800133,0x11900021,0x80080110,0x08801421,0x01189013,0x08032210,
	0x90182256,0x30100889,0x98010233,0x00089919,0xa8989999,0x90108110,0x988a9aa8,0x81101118,
	0x81018808,0x80880218,0x98081012,0x88a8809a,0x99009001,0x188009a8,0xaa888899,0x21908a9a,
	0x11100033,0x49aa8001,0x02099057,0x9ffe0101,0x119ba277,0xaffa4402,0x109de377,0xffb56311,
	0x108cf876,0xff232189,0x1810dc46,0xf9510bba,0x10200b24,0xc219aa90,0x00800880,0x9089a100,
	0x88009008,0x18801210,0x09900880,0x09100008,0x10000800,0x08180808,0x00189800,0x08888099,
	0x08810808,0x00918988,0x18008800,0x00889008,0x10880800,0x80888800,0x10888898,0x90000800,
	0xbbaccb10,0x00099aac,0xacb90345,0x320109ac,0xc9804221,0x102128aa,0xa8033119,0x80089989,
	0x91132318,0x9aaa998a,0xa3101108,0x009a9aab,0x91290038,0x08909abd,0x8008888b,0xc9808abb,
	0xa1188aa0,0x020118aa,0x9111a898,0x08814309,0x88888000,0x0aa55538,0xa9a09101,0x9d866660,
	0xa98899ad,0xe9464749,0xbba989cd,0x05443518,0xaaaabca3,0x7614328a,0xbba80246,0x421218ac,
	0x18889aa8,0x45298080,0x1118bff0,0x77adb800,0x1028bff6,0x7afffa11,0x0033afd4,0x6dffd210,
	0x80348fb3,0x4fff1331,0x08834ac3,0x2ff14341,0x888888c1,0x1f133213,0x18aa98b1,0x20230031,
	0x188809a1,0x08009821,0x80800880,0x18888821,0x00808881,0x11108128,0x08188891,0x22108108,
	0x01110809,0x81101009,0x10021121,0x99008990,0x18810111,0x18000808,0x10008888,0x01909890,
	0x12128890,0x99808122,0x1218beff,0xffea8012,0x318cffff,0xcbac0882,0x221280b9,0xaba91810,
	0x12346777,0x43180082,0x20182355,0x76318800,0x08db9ba8,0x22221000,0x08a9999c,0xca818090,
	0x10010119,0xca118298,0x10918acc,0x98988991,0x18999989,0x10081091,0x20991001,0x0980a912,
	0x12101220,0x01089011,0x21128000,0xa0aa9002,0x10210999,0x99981801,0x20211888,0x08800823,
	0xa8a98800,0x25631998,0x9aa89998,0x16775208,0x999a9aa9,0x9257739a,0x9aa9aa18,0x99167739,
	0xa9acbb98,0x99257750,0x9aab9aa0,0xaaa85753,0x99ab0ba9,0x8b090674,0x8001089a,0x8a1aa376,
	0x01118a99,0x998a8254,0x89918809,0x8a008044,0xaa801190,0x0a809012,0x99889109,0x80998081,
	0x8981100b,0x82088998,0x98811208,0xa9080898,0x89a8a009,0xaba88999,0x99aa0888,0x0a98a9a9,
	0x10088109,0xa9808880,0x011089a9,0xb8018a91,0x800001a0,0x98089a90,0x118000a9,0xa9888988,
	0x80081089,0x809a0988,0x889a09aa,0xa1880899,0x18a89ca9,0x91010298,0x89908880,0x8900238a,
	0x18000008,0xbd14529a,0x1000812b,0xbc662289,0x20098008,0x25738000,0x00808811,0x65319a80,
	0x88b89014,0x43129a80,0x1098a133,0x10988808,0x00010101,0x20980110,0x00011188,0x88922122,
	0xcbbab9aa,0x8baa9aba,0xbb9a8901,0x1111099b,0xb9a09113,0x10221899,0xa9000121,0x80232989,
	0x80332223,0x02320898,0x91443330,0x01121989,0x803409ba,0x00101220,0x90088aa0,0x21899108,
	0xbaa99901,0x0aaaa008,0xaaa9888a,0x9b998809,0xbaaaa880,0x90a88099,0xa9b98218,0x08012198,
	0x99012121,0x1002208a,0x90211222,0x1201898a,0xb8822322,0x131099a9,0x99808880,0x108899aa,
	0x10133534,0x32100000,0x11213100,0x08808808,0x08119008,0x08801008,0x10800001,0x98000009,
	0x98000008,0x10800009,0x08888000,0x00080080,0x08010011,0x10801231,0x01008010,0x98880883,
	0x11001001,0x00009110,0x09080001,0x12100900,0x88808813,0x212289cc,0x8bcb9aaf,0xfffedddc,
	0x8bcfffff,0xffffcaba,0x098acdff,0xfb811100,0x18001337,0x77223411,0x00014653,0x52222212,
	0x11100800,0x22101111,0x31008020,0x10001123,0x31100801,0x08090101,0x20108881,0x01888001,
	0x2081a912,0x08898990,0x10219818,0x119a8b82,0x1110988b,0xa31a9c91,0x2000098a,0xb4189900,
	0x11108118,0xf5419118,0x88888089,0xd6319100,0x19b1800c,0xf7280999,0x8892100f,0x97309a98,
	0x100320ce,0x16519b00,0x20aabdfc,0x25421891,0x109bdcea,0x44442880,0x000aaca3,0x43302022,
	0x80880988,0x88908880,0x88108801,0x80888000,0x10180019,0x00000310,0x90018801,0x00800028,
	0x00808088,0x98018000,0x11800880,0x08988088,0x00000018,0x80008110,0x1118a990,0x1988a088,
	0x88213210,0x98980988,0x99811141,0x00880008,0x8cfffffc,0xb8000080,0x9bfffffe,0x00008118,
	0x08099056,0x22008018,0x23467751,0x10080880,0x11223301,0x80000000,0x0018a999,0x88980990,
	0x89980108,0x88098899,0xa9924298,0x9899aaaa,0x90253aa0,0x18a89909,0x91561998,0x108900aa,
	0x946448e0,0x0a0008aa,0x855570f9,0x1a119089,0x033776fa,0x8018818a,0xa183770f,0xca0900aa,
	0x8002265d,0xca9bbbaa,0x98919128,0xa9b0a9b9,0x8899b803,0x98828800,0x98188890,0x88000819,
	0x98081111,0x18200218,0x99088221,0x20080009,0x98890800,0x08980888,0xa9a88010,0x1888808a,
	0x11211122,0x32412331,0x12281188,0x13241123,0x12189889,0x23021123,0x00a80010,0x23102214,
	0x00c91080,0x11201213,0x0adfcb03,0x74210080,0x28cffffe,0x652188c9,0x1989ffff,0x051088ab,
	0x283660ff,0xf2100119,0x9a01242f,0xd9001018,0x8abd8809,0xa8028810,0x09a9aa88,0xa1100880,
	0x1b020008,0xa0880001,0x080a9088,0x98880811,0x2110aa8a,0x9aa9a012,0x22209a9a,0x9aa90821,
	0x88810899,0x9b980810,0x10808000,0x81808080,0x10189828,0x90881888,0x10880998,0x89908908,
	0x81899998,0x91008989,0x089cdb8a,0xa899a9aa,0x089acddf,0xececdec9,0x8018aca9,0xaccbdcba,
	0x12433555,0x13099a88,0x13353445,0x66655474,0x21118001,0x24466776,0x0808009a,0x88225764,
	0x09800002,0x99981111,0x89898809,0x9899bba8,0x09a88981,0x1309a999,0x8808a980,0x80018881,
	0x01122355,0x44333212,0x12243433,0x22333022,0x22544180,0x18908000,0x325418a8,0x99caaba1,
	0x13120088,0x0990aa00,0x01000818,0x08898099,0x08982313,0x31211418,0x09811102,0x34456652,
	0x0218a988,0x83354343,0x11998128,0xacca1110,0x00088800,0x89aa8098,0x08a98021,0x29808dda,
	0x19deb88a,0x8081dffb,0x08cfffff,0xcbddedb9,0x00adfdbb,0xbccc9098,0x20088aac,0xba990881,
	0x80088080,0x08989880,0x08011001,0x01808898,0x90881192,0x20992100,0x801a8882,0x10298111,
	0x0809aa91,0x22200981,0x08089b98,0x91101008,0x80828a90,0xaa101010,0x89928013,0xdb010180,
	0x98caa044,0xfd109101,0x8989147f,0xf9188808,0x812835af,0xf1800080,0x110222cf,0xa1811818,
	0x090028b9,0x10980229,0x08898890,0x9a800218,0x9aaa9900,0x88800008,0x0898a810,0x02211008,
	0x8a9a9980,0x2230819a,0x9a8bbaa8,0x82333119,0x98a98ce9,0x98111428,0x8981188a,0xbaa33441,
	0x8022242c,0xbaf15243,0x82202138,0x8efc7543,0x818aa023,0x0ffa7530,0x88899022,0x9ff76200,
	0x08a08128,0x8d0609a9,0xaa80809a,0x9930a988,0x9a088808,0x08289989,0x8a918891,0x19080889,
	0x90100080,0x18001018,0x80009800,0x81891108,0x89880000,0x12020099,0x9a081081,0x20880898,
	0x988a899a,0xa0080889,0x89aaaaa9,0x03110090,0x89802180,0x33223280,0x89034210,0x21209011,
	0x99812335,0x62820131,0x80821474,0xbccaa901,0x8015161f,0xebbeda90,0x811421ef,0x1aacc910,
	0x013009dc,0x1989a011,0x82119afd,0x8acac988,0x910109ae,0xdcc91a99,0x88888218,0x98190088,
	0x80132010,0x3022080b,0x80009888,0x8998999a,0x98890188,0x99889aa0,0x89898999,0x8080a899,
	0x10181800,0x00111180,0x81088010,0x89008990,0x01099808,0xa2accdc8,0x88098999,0xacca9888,
	0x88881080,0x83467764,0x88081012,0x46677776,0x90009008,0xdfff8242,0x09800910,0xadefffda,
	0x80010080,0x12232a98,0x88900189,0x88008899,0x98919190,0x01108999,0x88a01981,0x80000098,
	0x88811100,0x01181280,0x80809801,0x12001110,0x819a9880,0x08080011,0x00091898,0x11088210,
	0x08099989,0x98999808,0x09098bba,0xabb9baa9,0x9989980b,0xbcbab9a8,0x999bcbea,0x09009090,
	0x99bcbaa8,0xaa9a0898,0x99db9a99,0x90098881,0x8aa880a8,0xacb80020,0x89899abd,0xfe814322,
	0x98a898ae,0x17653333,0x89a899a2,0x76423210,0x00a99032,0x30000001,0x88101422,0x11180220,
	0x01131101,0x00201212,0x10001200,0x80212442,0x01101011,0x21111422,0x81011223,0x13333208,
	0x80000810,0x11121000,0x89008123,0x10113211,0x80811200,0x02212352,0x88110200,0x12122253,
	0x02221231,0x08008252,0x11044532,0x00188132,0x99100246,0x30803109,0xab9abc13,0x20042bca,
	0x9aeeffe9,0x20ddffcb,0xacda89b9,0x9cffbda9,0xaaa2288c,0xac91008a,0x090118ab,0x12220119,
	0x80130008,0x02103300,0x80889a98,0xaa010008,0x0899a8bc,0xc9a90089,0x8988a99b,0xcaa89888,
	0x02201000,0x00801111,0x22008988,0x88080010,0x21080880,0x00889808,0x00080808,0x80809880,
	0x08088188,0x02111008,0x08802000,0x09881100,0x080010aa,0xa9099881,0x0bcc3663,0x101899a8,
	0x0bfffc27,0x40008998,0x118fffff,0x18080000,0x35760cff,0xc9000080,0x82466763,0x11098000,
	0x9aaaa008,0x01108000,0x0a9a9900,0x00889800,0x10808898,0x90909101,0x10000888,0x01101011,
	0x80008811,0x01020881,0x00101112,0x02890001,0x18100988,0x12088021,0x1108a009,0x25880410,
	0x1329ba9c,0x23c90112,0x0342a8cd,0x01b10822,0x1434263c,0xb9aacb01,0x03323771,0x80109241,
	0x122461a2,0x32344520,0x82132fe2,0x32235538,0x9888cfa8,0xa9baab89,0x9990ab89,0xa9abdeb8,
	0x9ab98989,0x80809a99,0x9a99cba8,0x80120088,0x088aa8a9,0x180b8180,0x0988889a,0x9a880088,
	0x23132112,0x22310023,0x32088991,0x10008012,0x21880913,0x88018002,0x10880981,0x81188010,
	0x808a0821,0x909a9a01,0x09901889,0xa888ba99,0x08809a9b,0xa8989999,0x11009880,0x88009091,
	0x23321081,0x11080003,0x32331221,0x22110043,0x18012331,0x35323531,0x89890100,0x35343521,
	0x0ab0a9ad,0xed843211,0x08a9a90f,0xfffecb82,0x2809dfff,0xfffffb01,0x21189baa,0xbbdb9922,
	0x10002021,0x11111100,0x10001012,0x11288001,0x18999a98,0x8a880801,0x188bbcd8,0x81100b90,
	0x200080bc,0xcb8988a8,0x15776776,0x310888a8,0x26777772,0x31108a98,0x008b9cff,0xb9808889,
	0x9dffffd9,0x01008189,0xaefd8022,0x10000088,0x8a813801,0x08001180,0x1020008a,0x90102000,
	0x18081000,0x09091000,0x18821120,0x1118a980,0x00080998,0x0881a981,0x01098100,0x10890000,
	0x01111101,0x01211021,0x11088aa9,0x888aa810,0x00acefff,0xfffec991,0x00bfffff,0xffff9a99,
	0x11999eff,0xffcd99a8,0x1813288a,0xa80b9a91,0x10112256,0x63000022,0x22381313,0x52081234,
	0x22010088,0x98800333,0x200010ab,0x88008011,0x12288901,0x88098801,0x11210002,0x02080881,
	0x28810880,0x88800002,0x11099818,0x88899010,0x23090808,0x98901212,0x12231122,0x11102123,
	0x01132110,0x9a981021,0x23233340,0xcfca9020,0x12323433,0x9dccd902,0x14321021,0x0cffd982,
	0x22880024,0x3fffeb00,0x21080117,0x4fffc911,0x32082147,0x2ffa9991,0x11800134,0x0ea80a80,
	0x28818022,0x9d909001,0x00988111,0x9b818801,0x18880080,0x99880081,0x28888888,0x809a8888,
	0x88908808,0x80989881,0x00099a10,0xa0888880,0x21088989,0xb0990901,0x12008818,0x08898082,
	0x8a8988a8,0x9aa999a8,0xaaa08898,0x89aa99a9,0xaa989808,0x88a92019,0x89091089,0x88110800,
	0x98090908,0x09989988,0x90099a18,0x81889000,0x918008aa,0x88010021,0x98889aaf,0xf9223438,
	0x90090850,0xfdc80099,0x91192234,0x8fffefdd,0x11111246,0x31cfffeb,0x14421913,0x5319dd99,
	0x0211108a,0x13321229,0x01012021,0x33557730,0x82221113,0x02456420,0x90102212,0x23323280,
	0xbbb9aaaa,0x998a999b,0x9b899900,0x099a99aa,0xb9888b82,0x08aa01aa,0xa8118a11,0x88988899,
	0x91338828,0xa8898008,0x84510108,0x18989998,0x14321099,0x088889ba,0x133128db,0x88809198,
	0x034370fd,0x88000800,0x254676fa,0x88808021,0x832675b9,0x0a8a9828,0x02256380,0x88880a89,
	0x03432308,0x00999999,0x93221009,0x9a9988a9,0xa0123220,0x8110889a,0xba009a80,0x00989a9b,
	0x22209998,0x23241122,0x2218efa1,0x32119812,0x208fff84,0x3208aa01,0x30affa43,0x999a8a80,
	0x28bff252,0xd8a089a1,0x19dfa47a,0xc0888821,0x09bc265a,0x81820343,0x08bb1349,0x89820123,
	0x88980208,0x88889000,0x09ab1188,0x10088901,0x089889c8,0x08081902,0x1a08a988,0x088a1982,
	0x18899881,0x889a9a01,0x18881208,0x0109a001,0x2180a109,0x81180321,0x21118000,0x80002213,
	0x118088aa,0x98998088,0x10089908,0x09aa0901,0x81800880,0x80181231,0x18889001,0x26777762,
	0x08800013,0x41000180,0x08188aae,0xfffffffd,0x99010989,0xacffdefd,0x98080911,0x43564388,
	0x00000000,0x18110101,0x18808088,0x01018011,0x08900818,0x80818001,0x80908880,0x00088110,
	0x08808111,0x01100801,0x00098880,0x08a0a800,0x00880008,0x88818881,0x11110000,0x00888000,
}; //first channel is topmost bit

// Layer: L2
// QuantType: 4bitsym
#define L2_active
#define L2_bitperweight 4
#define L2_incoming_weights 64
#define L2_outgoing_weights 32
const uint32_t L2_weights[] = {
	0x10400881,0x0baa8898,0x08904b88,0x9198f080,0x99909829,0x18191aa9,0x058a0498,0x0fa0c10a,
	0x2e81e113,0x31318034,0x110289c1,0x119048a1,0x082a2381,0x9f2a0839,0x4002b883,0xb333f912,
	0xb00901e3,0xa28bb1bf,0x99bf8101,0xb8388131,0x82101000,0x208e83f8,0x881903c8,0x0a3a929c,
	0x0aa1a96b,0x2a31b22a,0x1912d838,0xc213899c,0xb0594bc1,0x9b120b4c,0x029b8b21,0x8ba9181f,
	0x200f821e,0x823ca800,0x83a18204,0x8885b382,0x0a2b288e,0x04ba0180,0x231a84c1,0x4085898b,
	0x389881ba,0x0822c89a,0x88809023,0xa0caac80,0x83100a8c,0x1a8b1381,0x12ea9322,0x08af0808,
	0x808091a2,0x89a5aab7,0x8d42a199,0x8890a088,0xcb999102,0x1a0a2212,0x299be403,0x00919b0b,
	0x99b8b292,0x22839a88,0xa22989a9,0x29989022,0x040201a9,0x1d001010,0x19211112,0xb1402091,
	0x942911b9,0x90204c89,0xb43a800a,0xadb4aac1,0x40830088,0x81a3a199,0xb2180828,0xb1121db8,
	0x8d91fb31,0x49a20049,0x19959faa,0x08988002,0x83a0ab91,0x99210a8a,0xa8802018,0x1a920108,
	0xf1db8080,0x98a11401,0xb0189001,0x513c8220,0x088209e8,0xa1a12321,0x0f159800,0x00aa1127,
	0xa8990101,0x0b1a8192,0x0889a800,0x59389839,0x38403aa9,0x01088410,0x9984191a,0x1cae2884,
	0x8389299a,0x98c2381a,0x9a81181a,0x08b9a0d1,0x13c3b90a,0x30930b9b,0x90f81029,0x89884a20,
	0x0a39000b,0x04930d83,0x00322001,0x1eb01ba4,0x89b98030,0xa281c832,0x80b10002,0x04123bc2,
	0x82931ca1,0xaaa20281,0x9919018a,0x233f040b,0xa8009480,0x938118a8,0x2a13f800,0x114e9021,
	0x8c11910a,0x20d1a100,0x2d392aa1,0x989a189d,0x83a9a211,0x3d2a880b,0x80a13088,0x102a1080,
	0x2c91a010,0x3048b40c,0x23b0dc91,0xb4512120,0x01604ca8,0xbb3a2199,0x329b1201,0x8b08001e,
	0xd20f0098,0xc0808a8a,0xc8988230,0x8a91f003,0x0498a98d,0x22fd1284,0x8caa1182,0x88c01198,
	0xa18104aa,0xca1ea2c1,0xa0cf8322,0x91488028,0x01223111,0x8b8f9c11,0x0b89cccb,0x98981000,
	0x0092ab12,0x0958011c,0x80b3bb00,0x92009b89,0xa05f29a0,0xb7911284,0xa9288083,0x3898b109,
	0xa4191090,0xb2120c1a,0xa42a0010,0x8980c821,0x1813a818,0x02b41211,0xa31ad902,0x9181099a,
	0x08831c30,0x8b8f848b,0x08dc8918,0x9339210b,0xa8011181,0x8119bfb8,0x19208dd8,0x3a1aa430,
	0x2b120d31,0x50c20828,0x48940cda,0x80889ab8,0x00a99012,0x0c319080,0x90992039,0xa810b808,
	0x09c98290,0x9a08f39a,0x9ab8c88a,0x03200101,0x03100f92,0x388e2003,0xa9813288,0x8cc20129,
	0x00021912,0xb183b019,0x0ba00519,0x8a0108d9,0xbb801912,0x86adc4a0,0xaa01816e,0x30d0e9b1,
	0x2100134a,0x200880a1,0x193a9098,0xa08208aa,0xba8a01a0,0x0935091c,0x13889012,0x51288c89,
	0xa2981980,0x982aa193,0xb124a009,0x10889080,0x483120a9,0xa4a49021,0x99119839,0x82994d88,
	0x99838828,0x98da400b,0x8ba08088,0x8c1c098d,0x02c2a012,0xa200d9a0,0x8d122b29,0x0168889a,
	0x0a829928,0x04aa0e1a,0x85831983,0x29d89aa3,0x4a909108,0x1983e918,0x98b02829,0xa4913cc0,
	0x011083b2,0x30081199,0x234b0191,0x2b430382,0x1a281089,0x9132bada,0x3030889b,0x010288a9,
	0x9238321a,0xa2ba03b3,0x880a2121,0x80102988,0xb999a211,0x85acbd22,0x81198ad8,0x43010209,
	0x81110f21,0x0c040839,0x1882188c,0xd9829898,0xc2989110,0x190613a9,0xa1ab8820,0x0a91b20b,
}; //first channel is topmost bit

// Layer: L3
// QuantType: 4bitsym
#define L3_active
#define L3_bitperweight 4
#define L3_incoming_weights 32
#define L3_outgoing_weights 16
const uint32_t L3_weights[] = {
	0x097901c8,0x2d1008a1,0x11180803,0x98b8a3a9,0x9933a433,0x38b819d3,0x83b129a2,0x2a919882,
	0xb185a231,0x1181b80a,0x4823e102,0xa00a1e20,0x140a2822,0xa231b081,0x00bb9448,0x838090b8,
	0xb0804880,0x800a9488,0x59011988,0x053a8228,0x191b3019,0xb4a02802,0xab3a1221,0xb8a6b945,
	0x1a3acd82,0x0132902c,0x9a3509a1,0x2c083143,0x23912193,0xc299a4a0,0xa392099a,0xe2b9291a,
	0x0a13a205,0xbb342a21,0xa2a88ab0,0x0802d998,0x8290eb83,0x3bac8390,0x82102199,0x38825380,
	0x553a08d8,0x19dad150,0x9b318189,0x00982100,0x989a0961,0x22322809,0x1e992b19,0x6a320291,
	0x80898089,0x18898909,0x99998890,0x89888988,0x8a102290,0xa1a10384,0xd3821e98,0x80800049,
	0x40801808,0xba998119,0x80090010,0x209203b1,0x9aaa80dc,0x09339b89,0x92239206,0x910d991b,
}; //first channel is topmost bit

// Layer: L4
// QuantType: 4bitsym
#define L4_active
#define L4_bitperweight 4
#define L4_incoming_weights 16
#define L4_outgoing_weights 10
const uint32_t L4_weights[] = {
	0x099da228,0xaa3b0b9a,0x3ab04bab,0xba80898b,0xaaab1191,0x989a038a,0xa1ba8989,0xa4a2088a,
	0xa24888a0,0xab998b9a,0x9b999a20,0x3a938a89,0x8b0a8929,0x0aac0ba5,0xaa939ac1,0x923a880c,
	0x12a8a989,0x289b0188,0xa092b3b0,0x9aa18c89,
}; //first channel is topmost bit

#endif