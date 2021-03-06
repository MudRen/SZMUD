// Code of ShenZhou
// /d/huanghe/bangjob/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "流氓",
                "file"  :  "/d/city/npc/liumang",
                "area"  :  "扬州城中心",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  6,
        ]),

        ([      "name"  :  "壮汉",
                "file"  :  "/d/city/npc/man",
                "area"  :  "扬州城民屋",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "凌霜华",
                "file"  :  "/d/city/npc/shuanghua",
                "area"  :  "扬州翰林府",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "少妇",
                "file"  :  "/d/city/npc/woman",
                "area"  :  "扬州城民屋",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "张十五",
                "file"  :  "/d/city/npc/zhang15",
                "area"  :  "扬州街边酒馆",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "翠花",
                "file"  :  "/d/village/npc/cuihua",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  2,
        ]),

        ([      "name"  :  "地保",
                "file"  :  "/d/village/npc/dibao",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  5,
        ]),

        ([      "name"  :  "地痞",
                "file"  :  "/d/village/npc/dipi",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  2,
        ]),

        ([      "name"  :  "老大娘",
                "file"  :  "/d/village/npc/oldwoman",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "穷汉",
                "file"  :  "/d/village/npc/poorman",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "小流氓",
                "file"  :  "/d/village/npc/punk",
                "area"  :  "华山村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "进香客",
                "file"  :  "/d/emei/npc/xiang-ke",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "小土匪",
                "file"  :  "/d/emei/npc/xiao_tufei",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "年轻少妇",
                "file"  :  "/d/emei/npc/woman",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "仆人",
                "file"  :  "/d/emei/npc/puren",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "胖商人",
                "file"  :  "/d/foshan/npc/pang",
                "area"  :  "佛山镇",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "瘦商人",
                "file"  :  "/d/foshan/npc/shou",
                "area"  :  "佛山镇",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "张妈",
                "file"  :  "/d/forest/npc/zhangma",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "小桂子",
                "file"  :  "/d/jiaxing/npc/xiaoguizi",
                "area"  :  "嘉兴城",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "小喇嘛",
                "file"  :  "/d/qilian/npc/xlama",
                "area"  :  "兰州",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "苦力",
                "file"  :  "/d/quanzhou/npc/kuli",
                "area"  :  "泉州港",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  3,
        ]),

        ([      "name"  :  "庙祝",
                "file"  :  "/d/quanzhou/npc/miaozhu",
                "area"  :  "泉州港",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  4,
        ]),

        ([      "name"  :  "书生",
                "file"  :  "/d/taishan/npc/shu-sheng",
                "area"  :  "泰山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "挑夫",
                "file"  :  "/d/taishan/npc/tiao-fu",
                "area"  :  "泰山",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  1,
        ]),

        ([      "name"  :  "狗皮",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "野菊花",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "道德经「第一章」",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "道德经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "『星宿毒经』",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "持世陀罗尼经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "华山剑谱",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "唐诗选辑",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  15,
        ]),

        ([      "name"  :  "般若经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  12,
        ]),

        ([      "name"  :  "维摩经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "『少林拜师必读』",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "少林英雄令",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "罚恶令",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "赏善令",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "正气诀诀谱上卷",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "紫氤吟诀谱上卷",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

      
        ([      "name"  :  "法铃",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "法轮",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  1,
        ]),

        ([      "name"  :  "金光明经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "孔雀王咒经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "六字神咒经",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "狗皮膏药",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "易经《系辞篇》",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        
        ([      "name"  :  "粉红绸衫",
                "file"  :  "/d/city/obj/pink_cloth",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "闺房钥匙",
                "file"  :  "/d/city/obj/gfkey",
                "type"  :  "寻",
                "bonus" :  30,
                "score" :  5,
        ]),

        ([      "name"  :  "绿菊花",
                "file"  :  "/d/city/npc/obj/juhua1",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  12,
        ]),

        
        ([      "name"  :  "摆夷短裙",
                "file"  :  "/d/dali/npc/obj/byskirt",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  2,
        ]),

        

        ([      "name"  :  "蜡染布衣",
                "file"  :  "/d/dali/obj/ccloth",              
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  2,
        ]),

        ([      "name"  :  "台夷短裙",
                "file"  :  "/d/dali/npc/obj/tyduanqun",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "台夷头巾",
                "file"  :  "/d/dali/npc/obj/tyduanqun",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "天青夹绉纱褶子",
                "file"  :  "/d/dali/npc/obj/tqcloth",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "骷髅冠",
                "file"  :  "/d/qilian/obj/klguan",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "颅钵",
                "file"  :  "/d/qilian/obj/lubo",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "人头链",
                "file"  :  "/d/qilian/obj/rtlian",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

        ([      "name"  :  "皮靴",
                "file"  :  "/d/xingxiu/obj/pi-xue",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  5,
        ]),

        ([      "name"  :  "清心散",
                "file"  :  "/d/xingxiu/obj/xxqingxin-san",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "铜鼓",
                "file"  :  "/d/xingxiu/obj/tonggu",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  4,
        ]),

        ([      "name"  :  "铜号",
                "file"  :  "/d/xingxiu/obj/tonghao",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  3,
        ]),

       

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}



