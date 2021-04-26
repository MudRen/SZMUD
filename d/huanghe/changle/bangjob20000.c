// Code of ShenZhou
// /d/huanghe/bangjob/bangjob20000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/guidao",
                "where" :  "/d/city/zuixianlou2",
                "area"  :  "��������¥",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  6,
        ]),

        ([      "name"  :  "Τ����",
                "file"  :   "/d/city/npc/wei",
                "where" :  "/d/city/lichunyuan",
                "area"  :   "���ݳ�",
                "type"  :   "ɱ",
                "bonus" :   35,
        ]),

        ([      "name"  :  "�տն�",
                "file"  :  "/d/city/npc/qigai.c",
                "where" :  "/d/city/lichunyuan",
                "area"  :  "���ݳ�",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  20,
        ]),

        
        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/dao-ke",
                "where" :  "/d/taishan/yidao3",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  3,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/taishan/npc/jian-ke",
                "where" :  "/d/taishan/doumo",
                "area"  :  "̩ɽ",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  3,
        ]),

        ([      "name"  :  "����ͷ",
                "file"  :  "/d/wudang/npc/tufeitou",
                "where" :  "/d/wudang/tufeiwo3",
                "area"  :  "�䵱ɽ",
                "type"  :  "ɱ",
                "bonus" :  40,
                "score" :  17,
        ]),
        
         ([     "name"  : "���Ϲ�",
                "file"  :   "/d/jiaxing/npc/hai",
                "where" :  "/d/jiaxing/yanyu",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	35,
        ]),  
      
        ([      "name"  : "�߸���",
                "file"  :   "/kungfu/class/huashan/genming",
                "where" :  "/d/huashan/shanlu1",
                "area"  :   "��ɽ",
                "type"  :   "ɱ",
                "bonus" :	40,
       ]),  
       
        ([      "name"  : "�ϵ�ʿ",
                "file"  :   "/d/xixia/npc/laodao",
                "where" :  "/d/xixia/daoguan",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	40,
        ]),   
 
        ([      "name"  :   "��Ϊ����",
        	"file"  :   "/kungfu/class/shaolin/qing-wei",
        	"where" :  "/d/shaolin/guangchang1w",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	40,
        ]),   

 	([ 	"name" : "�����˳���", 
		"file" : "/d/xingxiu/obj/ha-robe.c", 
		"type" : "Ѱ", 	
		"bonus": 20,
	]),
	
	([	"name" : "������",
		"file" : "d/xingxiu/obj/blzhen", 
		"type" : "Ѱ" ,
		"bonus": 18,
	]),
	
	([	"name" : "������" ,
		"file" : "/clone/weapon/langya-bang.c", 
		"type" : "Ѱ" ,
		"bonus": 20,
	]),
	
	([	"name" : "��������" ,
		"file" : "/d/city/obj/xiupao.c", 
		"type" : "Ѱ" ,
		"bonus": 20,
	]),
	
	([	"name" : "�������䵶" ,
		"file" : "/d/xingxiu/npc/obj/wandao.c", 
		"type" : "Ѱ" ,
                "bonus": 20,
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
       
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
