// Code of ShenZhou
// /d/huanghe/changle/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����������",
                "file"  :  "/d/quanzhou/npc/trader",
                "where" :  "/d/quanzhou/alabo",
                "area"  :  "Ȫ�ݰ�����լ��",
                "type"  :  "ɱ",
                "bonus" :  38,
      
        ]),

        ([      "name"  :  "�в�ɮ",
                "file"  :   "/kungfu/class/shaolin/tuoboseng",
                "where" :  "/d/city/nandajie3",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :    38,
              
         ]),

        ([      "name"  :  "��åͷ",
                "file"  :  "/d/quanzhou/npc/liumangtou",
                "where" :  "/d/city/guangchang",
                "area"  :  "Ȫ�ݽֵ�",
                "type"  :  "ɱ",
                "bonus" :  38,
        ]),

        ([      "name"  :  "�����",
                "file"  :  "/d/huanghe/npc/shen-qinggang",
                "where" :  "/d/huanghe/huanghebang1",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  38,
        ]),


        ([      "name"  : "֪��ɮ",
                "file"  :   "/d/hangzhou/npc/zhike",
                "where" :  "/d/hangzhou/lingyin0",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	38,
        ]),   

	([      "name"  :  "�����",
                "file"  :   "/kungfu/class/gaibang/qiu-wanjia",
                "where" :  "/d/shaolin/jiulou2",
                "area"  :   "������",
                "type"  :   "ɱ",
                "bonus" :	38,
       	]),   
       	
       	([      "name"  :  "����",
                "file"  :   "/kungfu/class/shaolin/xu-ming",
                "where" :  "/d/shaolin/shanmen",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	38,
         ]),   


          
        ([      "name"  :  "����ɢ",
                "file"  :  "/d/xingxiu/obj/xxqingxin-san",
                "type"  :  "Ѱ",
                "bonus" :  20,
        ]),

        ([      "name"  :  "��ʬ��",
                "file"  :  "/d/xingxiu/obj/huashi",
                "type"  :  "Ѱ",
                "bonus" :  25,
        ]),

        ([      "name"  :  "�ٲݵ�",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  20,
        ]),

        ([      "name"  :  "�ۻ���",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  20,
          
        ]),

       ([      "name"  :  "�����赨ɢ",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  20,
                "score" :  8,
        ]),

        ([      "name"  :  "�޳���",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  25,
                "score" :  8,
        ]),

    
        ([      "name"  :  "��Ƥ��ҩ",
                "file"  :  " ",
                "type"  :  "Ѱ",
                "bonus" :  20,
           
        ]),

        ([      "name"  :  "¹��ǥ��",
                "file"  :  "/d/changbai/obj/qianzi",
                "type"  :  "Ѱ",
                "bonus" :  20,
              
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/changbai/obj/sbgun",
                "type"  :  "Ѱ",
                "bonus" :  20,
               
        ]),

        

        ([      "name"  :  "���ߵ�",
                "file"  :  "/d/xingxiu/npc/obj/shedan",
                "type"  :  "Ѱ",
                "bonus" :  15,
              
        ]),
        
        ([ 	"name" : "Ƥѥ", 
		"file" : "/d/xingxiu/obj/pi-xue.c", 
		"type" : "Ѱ", 
		"bonus": 18,
	]),
	

	([	"name" : "���", 
		"file" : "/clone/weapon/mabian.c", 
		"type" : "Ѱ", 
		"bonus": 20,
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


