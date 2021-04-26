// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "Ñªµ¶ÀÏ×æ",
                "file"  :   "/kungfu/class/xuedao/laozu",
                "where" :  "/d/xueshan/cave2",
                "area"  :   "Ñ©É½",
                "type"  :   "É±",
                "bonus" :	32,
        ]),       


       ([      "name" : "ÈË²Î¹û" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "Ñ°" ,
		"bonus": 25,
	]),
	
	([ 	"name"  :  "´óÑªÌÙ",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  15,
                "score" :  8,
        ]),

	([      "name"  :  "ÐþÌúÁî",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  18,
        ]),
	
	([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
