// Code of ShenZhou
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "�ػ�",
                "file"  :  "/d/quanzhou/npc/huihui",
                "where" :  "/d/quanzhou/qingjing",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  4,
        ]),

        ([      "name"  :  "��åͷ",
                "file"  :   "/d/city/npc/liumangtou",
                "where" :  "/d/city/guangchang",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	35,
         ]),  

         ([     "name"  :  "�η�����",
                "file"  :   "/d/taishan/npc/seng-ren",
                "where" :  "/d/taishan/shijin",
                "area"  :   "̩ɽ",
                "type"  :   "ɱ",
                "bonus" :	35,
               
         ]),   


        ([      "name"  :  "����",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "where" :  "/d/hangzhou/haidi",
                "area"  :  "�����庣��",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  3,
        ]),

        
        ([      "name"  : "�Ҷ�",
                "file"  :   "/d/taihu/npc/jiading",
                "where" :  "/d/taihu/damen",
                "area"  :   "����ׯ",
                "type"  :   "ɱ",
                "bonus" :	38,
               
         ]),   


        ([      "name"  :  "��ӥ����",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "where" :  "/d/hangzhou/hsmiao",
                "area"  :  "�����庣����",
                "type"  :  "ɱ",
                "bonus" :  35,
                "score" :  5,
        ]),
        
         ([     "name"  :  "��������",
                "file"  :   "/d/huashan/npc/haoke",
                "where" :  "/d/huashan/qingke",
                "area"  :   "��ɽ",
                "type"  :   "ɱ",
                "bonus" :	35,
         ]),   


        ([      "name"  :  "Ы�ӿ�",
                "file"  :  "/d/xingxiu/npc/scorp_shell",
                "type"  :  "Ѱ",
                "bonus" :  20,
        ]),

        ([      "name"  :  "����",
                "file"  :  "/d/xingxiu/npc/wg_shell",
                "type"  :  "Ѱ",
                "bonus" :  20,
	]),

        ([      "name"  :  "����˿",
                "file"  :  "/d/xingxiu/npc/zhusi",
                "type"  :  "Ѱ",
                "bonus" :  20,
        ]),

        ([      "name"  :  "ɳ���",
                "file"  :  "/d/xingxiu/npc/shachongke",
                "type"  :  "Ѱ",
                "bonus" :  20,
        ]),
       
	([	"name" : "���", 
		"file" : "d/xingxiu/npc/obj/bian.c", 
		"type" : "Ѱ", 
		"bonus" :  20,
	]),
	
	([	"name" : "�಼���",
		"file" : "/d/emei/npc/obj/nun-cloth.c", 
		"type" : "Ѱ" ,
		"bonus" :  15,
	]),
	
	([	"name" : "����Ƥ" ,
		"file" : "clone/drug/hulipi", 
		"type" : "Ѱ" ,
		"bonus" :  30,
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


