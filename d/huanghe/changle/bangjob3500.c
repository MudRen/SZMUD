// Code of ShenZhou
// /d/huanghe/changle/bangjob3000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�����",
                "file"  :  "/d/emei/npc/xiang-ke",
                "where" :  "/d/emei/baoguo1",
                "area"  :  "��üɽ",
                "type"  :  "ɱ",
                "bonus" :  38,
                "score" :  2,
        ]),
        
        ([      "name"  :  "��Ů",
                "file"  :   "/d/dali/npc/genu",
                "where" :  "/d/dali/jiulou2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	38,
        ]),              


        ([      "name"  :  "Ƥ����",
                "file"  :  "/d/changbai/npc/phshang",
                "where" :  "/d/changbai/jishi",
                "area"  :  "����ɽ����",
                "type"  :  "ɱ",
                "bonus" :  45,
                "score" :  3,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/foshan/npc/pang",
                "where" :  "/d/foshan/yxlou2",
                "area"  :  "��ɽ��",
                "type"  :  "ɱ",
                "bonus" :  38,
                "score" :  1,
        ]),

       
        ([      "name"  :  "Ұ�ջ�",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "Ѱ",
                "bonus" :  3,
                "score" :  1,
        ]),

        ([      "name"  :  "��Ƥ",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "Ѱ",
                "bonus" :  3,
                "score" :  1,
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

        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),

        ([      "type"  :  "���",
        ]),
        
        ([      "type"  :  "���",
        ]),
        
        ([      "type"  :  "���",
        ]),
        
        ([      "type"  :  "���",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}



