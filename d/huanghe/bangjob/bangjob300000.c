// Code of ShenZhou
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
	([      "name"  :  "����",
                "file"  :  "/d/foshan/npc/baoshu",
                "where" :  "/d/shaolin/zoulang8",
                "area"  :  "������",
                "type"  :  "ɱ",
                "bonus" :  32,
                "score" :  12,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "where" :  "/d/huanghe/xiayiting",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  25,
                "score" :  30,
        ]),
        
        ([      "name"  :  "����",
                "file"  :   "/kungfu/class/shaolin/cheng-mie",
                "where" :  "/d/shaolin/luohan8",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "��֪",
                "file"  :   "/kungfu/class/shaolin/cheng-zhi",
                "where" :  "/d/shaolin/luohan2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "����",
                "file"  :   "/kungfu/class/shaolin/cheng-xin",
                "where" :  "/d/shaolin/banruo6",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "��˼",
                "file"  :   "/kungfu/class/shaolin/cheng-si",
                "where" :  "/d/shaolin/banruo3",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	28,
        ]), 
        
        ([      "name"  :  "����",
                "file"  :   "/kungfu/class/shaolin/cheng-yi",
                "where" :  "/d/shaolin/banruo2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	28,
        ]), 
         
        ([      "name"  :  "����",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "�ܵ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "ָ��",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "ʾ��",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
        
        ([      "type"  :  "̯��",
        ]),
                
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
