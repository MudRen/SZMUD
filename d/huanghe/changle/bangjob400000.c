// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([     "name"  :  "½��ֹ",
                "file"  :   "/d/city/npc/gaozhi",
                "where" :  "/d/city/ymzhengting",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	32,
               
         ]),  

        ([      "name"  :  "��һ��",
                "file"  :  "/d/changbai/npc/teng",
                "where" :  "/d/changbai/nancheng",
                "area"  :  "�ض�",
                "type"  :  "ɱ",
                "bonus" :  32,
        ]),
        
        ([      "name"  :  "����ͬ",
                "file"  :   "/d/city/npc/yutong",
                "where" :  "/d/city/neizhai",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	32,
              
         ]),
         
        ([      "name"  : "������",
                "file"  :   "/d/village/npc/smith",
                "where" :  "/d/village/smithy1",
                "area"  :   "��ɽ��",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   

         ([     "name"  :  "һƷ����ʿ",
                "file"  :   "/d/xixia/npc/ypshi",
                "where" :  "/d/xixia/ypgate",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   

 

	([      "name"  :   "ժ����",
                "file"  :   "/kungfu/class/xingxiu/zhaixing",
                "where" :  "/d/xingxiu/cave",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	32,
         ]),    
         
/*
         ([     "name"  :  "�ް�Ȫ",
                "file"  :   "/d/dali/npc/cui",
                "where" :  "/d/dali/wangfu2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	32,
         ]),      
*/


        ([      "name"  :  "�˲�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  15,
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


	
	([	"name" : "��צ" ,
		"file" : "/d/xixia/obj/gangzhua.c", 
		"type" : "Ѱ" ,
		"bonus": 20,
	]),

	
	([	"name" : "��ս�" ,
		"file" : "clone/weapon/qinggang-jian", 
		"type" : "Ѱ" ,
		"bonus":15,
	]),
	
/*
	([	"name" : "��Ҷ��" ,
		"file" : "/d/xixia/obj/liuyedao.c", 
		"type" : "Ѱ" ,
		"bonus": 18,
	]),
*/

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
        

        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),

});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
