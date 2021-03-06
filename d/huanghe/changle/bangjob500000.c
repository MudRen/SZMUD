// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "丁典",
                "file"  :  "/d/city/npc/dingdian",
                "where" :  "/d/city/jail",
                "area"  :  "扬州城监狱",
                "type"  :  "杀",
                "bonus" :  32,
               
        ]),

        ([      "name"  :  "滕一雷",
                "file"  :  "/d/changbai/npc/teng",
                "where" :  "/d/changbai/nancheng",
                "area"  :  "关东",
                "type"  :  "杀",
                "bonus" :  70,
                "score" :  30,
        ]),

        ([      "name"  : "曲三",
                "file"  :   "/d/hangzhou/npc/qusan",
                "where" :  "/d/hangzhou/jiudian",
                "area"  :   "杭州",
                "type"  :   "杀",
                "bonus" :	30,
        ]),   
        
        ([       "name"  :  "云中鹤",
                "file"  :   "/d/xixia/npc/yun",
                "where" :  "/d/xixia/jytang",
                "area"  :   "西夏",
                "type"  :   "杀",
                "bonus" :	35,
        ]),   
        
        ([      "name"  :  "石人武士",
                "file"  :   "/d/xixia/npc/lingshi",
                "where" :  "/d/xixia/wangling",
                "area"  :   "西夏",
                "type"  :   "杀",
                "bonus" :	35,
        ]),   
        
         ([     "name"  :  "南海鳄神",
                "file"  :   "/d/xixia/npc/eshen",
                "where" :  "/d/xixia/dawu",
                "area"  :   "西夏",
                "type"  :   "杀",
                "bonus" :	35,
          ]),   
        
        ([      "name"  : "赛总管",
                "file"  :   "/d/changbai/npc/sai",
                "where" :  "/d/changbai/tieby",
                "area"  :   "长白",
                "type"  :   "杀",
                "bonus" :	34,
         ]),   

        ([      "name"  :  "田归农",
                "file"  :   "/d/changbai/npc/tian",
                "where" :  "/d/changbai/yuzf",
                "area"  :   "长白",
                "type"  :   "杀",
                "bonus" :	30,
        ]),  
        
        ([     "name"  :  "冯锡范",
                "file"  :   "/d/changbai/npc/feng",
                "where" :  "/d/changbai/shguan2",
                "area"  :   "长白",
                "type"  :   "杀",
                "bonus" :	30,
        ]),   
        
        ([      "name"  :  "刘处玄",
                "file"  :   "/kungfu/class/quanzhen/liu",
                "where" :  "/d/zhongnan/chanshen",
                "area"  :   "全真",
                "type"  :   "杀",
                "bonus" :	30,
        ]),   
        
        ([      "name"  :   "水岱",
                "file"  :   "/d/xueshan/npc/shui",
                "where" :  "/d/xueshan/dshanlu",
                "area"  :   "雪山",
                "type"  :   "杀",
                "bonus" :	28,
         ]),     
        
    
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
        
        ([      "type"  :  "送礼",
        ]),
               
          
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
