// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "Ѫ������",
                "file"  :   "/kungfu/class/xuedao/laozu",
                "where" :  "/d/xueshan/cave2",
                "area"  :   "ѩɽ",
                "type"  :   "ɱ",
                "bonus" :	32,
        ]),       


/*

       ([      "name" : "�˲ι�" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "Ѱ" ,
		"bonus": 25,
	]),
	
*/

                  ([      "name" : "���ߵ�" ,  
                            "file" : "/clone/drug/mangshe-dan",   
                            "type" : "Ѱ" ,  
                            "bonus": 30, 
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
        
        
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
