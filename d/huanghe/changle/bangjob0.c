// Code of ShenZhou
// /d/huanghe/changle/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
	([      "name"  :  "Ů��",
                "file"  :   "/d/city/npc/girl",
                "where" :  "/d/city/dongnanjie",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :    40,
        ]), 
	         
         ([     "name"  :  "�ٸ�",
                "file"  :   "/d/city/npc/woman",
                "where" :  "/d/city/minwu2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	40,
              
         ]),
         
         ([    "name"  :   "ׯ�ʳ�",
                "file"  :   " /d/hangzhou/npc/zhuang",
                "where" :  "/d/taihu/nanxun",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	40,
             
           ]),
           
        ([      "name"  : "С����",
                "file"  :   "/d/jiaxing/npc/xiaoguizi",
                "where" :  "/d/jiaxing/yanyu",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	40,
         ]),   
         
        
        ([      "name"  :  "С��",
                "file"  :   "/d/village/npc/kid",
                "where" :  "/d/emei/house1",
                "area"  :   "��ɽ��",
                "type"  :   "ɱ",
                "bonus" :	35,
        ]),   
        
         ([     "name"  :  "��Ʀ",
                "file"  :   "/d/village/npc/dipii",
                "where" :  "/d/village/alley2",
                "area"  :   "��ɽ��",
                "type"  :   "ɱ",
                "bonus" :	40,
         ]),   
         
       
       
        ([      "name" : "������", 
		"file" : " /d/xingxiu/npc/obj/dongbula.c ", 
		"type" : "Ѱ", 
		"bonus" : 20, 
	]), 

	([      "name" : "��Ь", 
		"file" : " /d/village/npc/obj/shoes ", 
		"type" : "Ѱ", 
		"bonus" : 20, 
	]), 
	
	([      "name" : "����", 
		"file" : " /d/village/npc/obj/rope ", 
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "����֦", 
		"file" : " /d/city/obj/branch2.c ", 
		"type" : "Ѱ", 
		"bonus" : 15, 
	]), 
	
	([      "name" : "����", 
		"file" : " /d/shaolin/obj/caoliao.c ", 
		"type" : "Ѱ", 
		"bonus" : 15, 
	]), 
	
	([ 	"name" : "��ñ", 
		"file" : " /d/quanzhou/npc/obj/caomao ", 
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "��Ԫ��", 
		"file" : " clone/drug/guiyuan ", 
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "����", 
		"file" : " /d/city/obj/doupeng ", 
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 

	([      "name" : "���", 
		"file" : "/clone/money/pocket.c" ,
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 
	
	([ 	"name" : "ʯ����",
		"file" : "/d/city/npc/obj/flower/shi_hulan.c" ,
		"type" : "Ѱ",
		"bonus" : 18,  
	]), 
	
	([ 	"name" : "���", 
		"file" : "/d/city/npc/obj/xinfeng1.c" ,
		"type" : "Ѱ",
		"bonus" : 18,  
	]), 

	([ 	"name" : "ӣ��",
		"file" : "/d/city/npc/obj/cherry.c",
		"type" : "Ѱ",
		"bonus" : 18,  
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
        
        ([      "type"  :  "����",
        ]),
        
        ([      "type"  :  "����",
        ]),
        
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "���",
	]),
	
	([	"type"  :  "̯��",
	]),
	
	([	"type"  :  "̯��",
	]),
	
	([	"type"  :  "̯��",
	]),
		
		
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


