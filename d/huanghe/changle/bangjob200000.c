// Code of ShenZhou
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "宝树",
                "file"  :  "/d/foshan/npc/baoshu",
                "where" :  "/d/shaolin/zoulang8",
                "area"  :  "少林寺",
                "type"  :  "杀",
                "bonus" :  32,
                "score" :  12,
        ]),

        ([      "name"  :  "瘦头陀",
                "file"  :   "/kungfu/class/shenlong/shou",
                "where" :  "/d/city/duchang",
                "area"  :   "扬州",
                "type"  :   "杀",
                "bonus" :	30,
               
         ]),

        ([      "name"  :  "梁子翁",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "where" :  "/d/huanghe/xiayiting",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  30,
               
        ]),

        ([      "name"  :  "日本浪人",
                "file"  :  "/d/quanzhou/npc/langren",
                "where" :  "/d/quanzhou/anhai",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  7,
        ]),

        ([      "name"  :  "杨铁心",
                "file"  :  "/d/hangzhou/npc/yang",
                "where" :  "/d/hangzhou/village",
                "area"  :  "牛家村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "郭啸天",
                "file"  :  "/d/hangzhou/npc/guo",
                "where" :  "/d/hangzhou/village",
                "area"  :  "牛家村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),
        
         ([     "name"  : "李四",
                "file"  :   "/clone/npc/xiejian",
                "where" :  "/d/village/shop",
                "area"  :   "华山村",
                "type"  :   "杀",
                "bonus" :	30,
         ]),   
         
  	([      "name"  :   "慧合尊者",
                "file"  :   " /kungfu/class/shaolin/hui-he",
                "where" :  "/d/shaolin/hsyuan1",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	30,
   	]),   
   	
   	([      "name"  :  "李志常",
                "file"  :   "/kungfu/class/quanzhen/li",
                "where" :  "/d/zhongnan/jingge",
                "area"  :   "全真",
                "type"  :   "杀",
                "bonus" :	30,
         ]),   

         ([     "name"  :  "胜谛",
                "file"  :   "/kungfu/class/xuedao/shengdi",
                "where" :  "/d/xueshan/shangu1",
                "area"  :   "雪山",
                "type"  :   "杀",
                "bonus" :	30,
          ]),   
          


 	([      "name"  :  "静真师太",
                "file"  :   "/kungfu/class/emei/jingzhen",
                "where" :  "/d/emei/fushou",
                "area"  :   "峨嵋",
                "type"  :   "杀",
                "bonus" :	30,
        ]),       
   
        ([      "name"  :  "虎骨",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  15,
        ]),

	([	"name" : "金边黑布袈裟" ,
		"file" : "d/shaolin/obj/cheng-cloth", 
		"type" : "寻" ,
		"bonus": 15,
	]),
		

        ([      "name"  :  "指环",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  15,
        ]),
        
	([      "name" : " 禅杖" ,
		"file" : "clone/weapon/chanzhang", 
		"type" : "寻" ,
		"bonus": 14,
	]),
	
	([      "type"  :  "示威",
        ]),
        
        ([      "type"  :  "示威",
        ]),
        
        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "截镖",
        ]),
        
        ([      "type"  :  "截镖",
        ]),
        
        ([      "type"  :  "截镖",
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
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),
        
        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
