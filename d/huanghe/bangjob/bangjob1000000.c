// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
       ([       "name"  :  "Ľ�ݲ�",
                "file"  :   "/clone/npc/murong",
                "where" :  "random",
                "area"  :   "�����߶�",
                "type"  :   "ɱ",
                "bonus" :  35,

        ]),
        
        
        ([      "name"  :  "������",
                "file"  :   "/clone/npc/zuo",
                "where" :  "random",
                "area"  :   "�����߶�",
                "type"  :   "ɱ",
                "bonus" :    35,
               
         ]),

        ([      "name"  : "��Ī��",
                "file"  :   "/kungfu/class/gumu/limochou",
                "where" :  "/d/jiaxing/nanhu",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),
         
         ([     "name"  :   "������",
                "file"  :   "/d/changbai/npc/yu",
                "where" :  "/d/changbai/muqiao",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   
         
         ([     "name"  :   "��Զɽ",
                "file"  :   "/d/changbai/npc/xiao",
                "where" :  "/d/changbai/guandao1",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   

        ([      "name"  :  "���Ѵ�ʦ",
                "file"  :   "/kungfu/class/shaolin/xuan-nan",
                "where" :  "/d/shaolin/banruo5",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),   

	([      "name"  :   "����Ϫ",
                "file"  :   "/kungfu/class/wudang/xi",
                "where" :  "/d/wudang/hd_zoulang",
                "area"  :   "�䵱",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   

       
       ([      "name" : "�˲ι�" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "Ѱ" ,
		"bonus": 25,
	]),
	
	([	"name" : "��β��" ,
		"file" : "/d/xixia/obj/eweibian.c", 
		"type" : "Ѱ" ,
		"bonus": 15,
	]),

	([      "name"  :  "���ھ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  15,
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

});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
