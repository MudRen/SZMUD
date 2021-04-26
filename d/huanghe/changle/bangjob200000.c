// Code of ShenZhou
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/foshan/npc/baoshu",
                "where" :  "/d/shaolin/zoulang8",
                "area"  :  "������",
                "type"  :  "ɱ",
                "bonus" :  32,
                "score" :  12,
        ]),

        ([      "name"  :  "��ͷ��",
                "file"  :   "/kungfu/class/shenlong/shou",
                "where" :  "/d/city/duchang",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
               
         ]),

        ([      "name"  :  "������",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "where" :  "/d/huanghe/xiayiting",
                "area"  :  "�ƺӰ�",
                "type"  :  "ɱ",
                "bonus" :  30,
               
        ]),

        ([      "name"  :  "�ձ�����",
                "file"  :  "/d/quanzhou/npc/langren",
                "where" :  "/d/quanzhou/anhai",
                "area"  :  "Ȫ��",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  7,
        ]),

        ([      "name"  :  "������",
                "file"  :  "/d/hangzhou/npc/yang",
                "where" :  "/d/hangzhou/village",
                "area"  :  "ţ�Ҵ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "��Х��",
                "file"  :  "/d/hangzhou/npc/guo",
                "where" :  "/d/hangzhou/village",
                "area"  :  "ţ�Ҵ�",
                "type"  :  "ɱ",
                "bonus" :  30,
                "score" :  10,
        ]),
        
         ([     "name"  : "����",
                "file"  :   "/clone/npc/xiejian",
                "where" :  "/d/village/shop",
                "area"  :   "��ɽ��",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   
         
  	([      "name"  :   "�ۺ�����",
                "file"  :   " /kungfu/class/shaolin/hui-he",
                "where" :  "/d/shaolin/hsyuan1",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
   	]),   
   	
   	([      "name"  :  "��־��",
                "file"  :   "/kungfu/class/quanzhen/li",
                "where" :  "/d/zhongnan/jingge",
                "area"  :   "ȫ��",
                "type"  :   "ɱ",
                "bonus" :	30,
         ]),   

         ([     "name"  :  "ʤ��",
                "file"  :   "/kungfu/class/xuedao/shengdi",
                "where" :  "/d/xueshan/shangu1",
                "area"  :   "ѩɽ",
                "type"  :   "ɱ",
                "bonus" :	30,
          ]),   
          


 	([      "name"  :  "����ʦ̫",
                "file"  :   "/kungfu/class/emei/jingzhen",
                "where" :  "/d/emei/fushou",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),       
   
        ([      "name"  :  "����",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  15,
        ]),

	([	"name" : "��ߺڲ�����" ,
		"file" : "d/shaolin/obj/cheng-cloth", 
		"type" : "Ѱ" ,
		"bonus": 15,
	]),
		

        ([      "name"  :  "ָ��",
                "file"  :  "  ",
                "type"  :  "Ѱ",
                "bonus" :  15,
        ]),
        
	([      "name" : " ����" ,
		"file" : "clone/weapon/chanzhang", 
		"type" : "Ѱ" ,
		"bonus": 14,
	]),
	
	([      "type"  :  "ʾ��",
        ]),
        
        ([      "type"  :  "ʾ��",
        ]),
        
        ([      "type"  :  "ʾ��",
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
