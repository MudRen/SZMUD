// Code of ShenZhou
// /d/huanghe/changle/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "进香客",
                "file"  :  "/d/emei/npc/xiang-ke",
                "where" :  "/d/emei/baoguo1",
                "area"  :  "峨眉山",
                "type"  :  "杀",
                "bonus" :  38,
                "score" :  2,
        ]),
        
        ([      "name"  :  "歌女",
                "file"  :   "/d/dali/npc/genu",
                "where" :  "/d/dali/jiulou2",
                "area"  :   "大理",
                "type"  :   "杀",
                "bonus" :	38,
        ]),              


        ([      "name"  :  "皮货商",
                "file"  :  "/d/changbai/npc/phshang",
                "where" :  "/d/changbai/jishi",
                "area"  :  "长白山集市",
                "type"  :  "杀",
                "bonus" :  45,
                "score" :  3,
        ]),

        ([      "name"  :  "胖商人",
                "file"  :  "/d/foshan/npc/pang",
                "where" :  "/d/foshan/yxlou2",
                "area"  :  "佛山镇",
                "type"  :  "杀",
                "bonus" :  38,
                "score" :  1,
        ]),

       
        ([      "name"  :  "野菊花",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "寻",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "name"  :  "狗皮",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "寻",
                "bonus" :  3,
                "score" :  1,
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

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}



