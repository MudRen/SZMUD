// Code of ShenZhou
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
	([      "name"  :  "宝树",
                "file"  :  "/d/foshan/npc/baoshu",
                "where" :  "/d/shaolin/zoulang8",
                "area"  :  "少林寺",
                "type"  :  "杀",
                "bonus" :  32,
                "score" :  12,
        ]),

        ([      "name"  :  "梁子翁",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "where" :  "/d/huanghe/xiayiting",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  25,
                "score" :  30,
        ]),
        
        ([      "name"  :  "澄灭",
                "file"  :   "/kungfu/class/shaolin/cheng-mie",
                "where" :  "/d/shaolin/luohan8",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "澄知",
                "file"  :   "/kungfu/class/shaolin/cheng-zhi",
                "where" :  "/d/shaolin/luohan2",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "澄心",
                "file"  :   "/kungfu/class/shaolin/cheng-xin",
                "where" :  "/d/shaolin/banruo6",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "澄思",
                "file"  :   "/kungfu/class/shaolin/cheng-si",
                "where" :  "/d/shaolin/banruo3",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "澄意",
                "file"  :   "/kungfu/class/shaolin/cheng-yi",
                "where" :  "/d/shaolin/banruo2",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	28,
        ]), 
         
        ([      "name"  :  "虎骨",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "熊胆",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "指环",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
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
