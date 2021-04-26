// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "����",
                "file"  :  "/d/city/npc/dingdian",
                "where" :  "/d/city/jail",
                "area"  :  "���ݳǼ���",
                "type"  :  "ɱ",
                "bonus" :  32,
               
        ]),

        ([      "name"  :  "��һ��",
                "file"  :  "/d/changbai/npc/teng",
                "where" :  "/d/changbai/nancheng",
                "area"  :  "�ض�",
                "type"  :  "ɱ",
                "bonus" :  70,
                "score" :  30,
        ]),

        ([      "name"  : "����",
                "file"  :   "/d/hangzhou/npc/qusan",
                "where" :  "/d/hangzhou/jiudian",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),   
        
        ([       "name"  :  "���к�",
                "file"  :   "/d/xixia/npc/yun",
                "where" :  "/d/xixia/jytang",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	35,
        ]),   
        
        ([      "name"  :  "ʯ����ʿ",
                "file"  :   "/d/xixia/npc/lingshi",
                "where" :  "/d/xixia/wangling",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	35,
        ]),   
        
         ([     "name"  :  "�Ϻ�����",
                "file"  :   "/d/xixia/npc/eshen",
                "where" :  "/d/xixia/dawu",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	35,
          ]),   
        
        ([      "name"  : "���ܹ�",
                "file"  :   "/d/changbai/npc/sai",
                "where" :  "/d/changbai/tieby",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	34,
         ]),   

        ([      "name"  :  "���ũ",
                "file"  :   "/d/changbai/npc/tian",
                "where" :  "/d/changbai/yuzf",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),  
        
        ([     "name"  :  "������",
                "file"  :   "/d/changbai/npc/feng",
                "where" :  "/d/changbai/shguan2",
                "area"  :   "����",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),   
        
        ([      "name"  :  "������",
                "file"  :   "/kungfu/class/quanzhen/liu",
                "where" :  "/d/zhongnan/chanshen",
                "area"  :   "ȫ��",
                "type"  :   "ɱ",
                "bonus" :	30,
        ]),   
        
        ([      "name"  :   "ˮ�",
                "file"  :   "/d/xueshan/npc/shui",
                "where" :  "/d/xueshan/dshanlu",
                "area"  :   "ѩɽ",
                "type"  :   "ɱ",
                "bonus" :	28,
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
        
        ([      "type"  :  "����",
        ]),
               
          
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
