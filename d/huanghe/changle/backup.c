// Code of ShenZhou
// /d/huanghe/changle/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
	([	"name" : "Ѽ��", 
	  	"file" : " /d/city/npc/obj/pear.c ", 
                "type" : "Ѱ", 
		"bonus" : 25,
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
		"bonus" : 15, 
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
		"bonus" : 15, 
	]), 
	
	([      "name" : "��Ԫ��", 
		"file" : " clone/drug/guiyuan ", 
		"type" : "Ѱ", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "����", 
		"file" : " /d/city/obj/doupeng ", 
		"type" : "Ѱ", 
		"bonus" : 15, 
	]), 

	([      "name" : "���", 
		"file" : "/clone/money/pocket.c" ,
		"type" : "Ѱ", 
		"bonus" : 15, 
	]), 
	
	([ 	"name" : "ʯ����",
		"file" : "/d/city/npc/obj/flower/shi_hulan.c" ,
		"type" : "Ѱ",
		"bonus" : 15,  
	]), 
	
	([ 	"name" : "���", 
		"file" : "/d/city/npc/obj/xinfeng1.c" ,
		"type" : "Ѱ",
		"bonus" : 15,  
	]), 

	([ 	"name" : "������Ƭ",
		"file" : "/d/city/npc/tea/guapian.c" ,
		"type" : "Ѱ",
		"bonus" : 15,  
	]), 
	
	([ 	"name" : "��ʯ��ָ" ,
		"file" : "/d/city/obj/ring-diamond.c",
		"type" : "Ѱ",
		"bonus" : 15,  
	]), 
	
	([ 	"name" : "��ʯ����",
		"file" : "/d/city/obj/earring-diamond.c",
		"type" : "Ѱ",
		"bonus" : 15,  
	]), 

	([ 	"name" : "����",
		"file" : "/d/changbai/npc/gourou.c" ,
		"type" : "Ѱ",
		"bonus" : 15,  
	]),
	
	([	"name" : "��������", 
		"file" : "/d/qilian/obj/paomo.c", 
		"type" : "Ѱ",
		"bonus" : 15,  
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


