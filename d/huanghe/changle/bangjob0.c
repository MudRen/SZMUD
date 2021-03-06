// Code of ShenZhou
// /d/huanghe/changle/bangjob10000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
	([      "name"  :  "女孩",
                "file"  :   "/d/city/npc/girl",
                "where" :  "/d/city/dongnanjie",
                "area"  :   "扬州",
                "type"  :   "杀",
                "bonus" :    40,
        ]), 
	         
         ([     "name"  :  "少妇",
                "file"  :   "/d/city/npc/woman",
                "where" :  "/d/city/minwu2",
                "area"  :   "扬州",
                "type"  :   "杀",
                "bonus" :	40,
              
         ]),
         
         ([    "name"  :   "庄允城",
                "file"  :   " /d/hangzhou/npc/zhuang",
                "where" :  "/d/taihu/nanxun",
                "area"  :   "杭州",
                "type"  :   "杀",
                "bonus" :	40,
             
           ]),
           
        ([      "name"  : "小桂子",
                "file"  :   "/d/jiaxing/npc/xiaoguizi",
                "where" :  "/d/jiaxing/yanyu",
                "area"  :   "嘉兴",
                "type"  :   "杀",
                "bonus" :	40,
         ]),   
         
        
        ([      "name"  :  "小孩",
                "file"  :   "/d/village/npc/kid",
                "where" :  "/d/emei/house1",
                "area"  :   "华山村",
                "type"  :   "杀",
                "bonus" :	35,
        ]),   
        
         ([     "name"  :  "地痞",
                "file"  :   "/d/village/npc/dipii",
                "where" :  "/d/village/alley2",
                "area"  :   "华山村",
                "type"  :   "杀",
                "bonus" :	40,
         ]),   
         
       
       
        ([      "name" : "冬不拉", 
		"file" : " /d/xingxiu/npc/obj/dongbula.c ", 
		"type" : "寻", 
		"bonus" : 20, 
	]), 

	([      "name" : "麻鞋", 
		"file" : " /d/village/npc/obj/shoes ", 
		"type" : "寻", 
		"bonus" : 20, 
	]), 
	
	([      "name" : "绳子", 
		"file" : " /d/village/npc/obj/rope ", 
		"type" : "寻", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "大树枝", 
		"file" : " /d/city/obj/branch2.c ", 
		"type" : "寻", 
		"bonus" : 15, 
	]), 
	
	([      "name" : "草料", 
		"file" : " /d/shaolin/obj/caoliao.c ", 
		"type" : "寻", 
		"bonus" : 15, 
	]), 
	
	([ 	"name" : "草帽", 
		"file" : " /d/quanzhou/npc/obj/caomao ", 
		"type" : "寻", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "归元丹", 
		"file" : " clone/drug/guiyuan ", 
		"type" : "寻", 
		"bonus" : 18, 
	]), 
	
	([      "name" : "斗篷", 
		"file" : " /d/city/obj/doupeng ", 
		"type" : "寻", 
		"bonus" : 18, 
	]), 

	([      "name" : "红包", 
		"file" : "/clone/money/pocket.c" ,
		"type" : "寻", 
		"bonus" : 18, 
	]), 
	
	([ 	"name" : "石斛兰",
		"file" : "/d/city/npc/obj/flower/shi_hulan.c" ,
		"type" : "寻",
		"bonus" : 18,  
	]), 
	
	([ 	"name" : "缄封", 
		"file" : "/d/city/npc/obj/xinfeng1.c" ,
		"type" : "寻",
		"bonus" : 18,  
	]), 

	([ 	"name" : "樱桃",
		"file" : "/d/city/npc/obj/cherry.c",
		"type" : "寻",
		"bonus" : 18,  
	]), 
	
	

		
	([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
	([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
                
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
        ([      "type"  :  "买卖",
        ]),
        
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "伙计",
	]),
	
	([	"type"  :  "摊费",
	]),
	
	([	"type"  :  "摊费",
	]),
	
	([	"type"  :  "摊费",
	]),
		
		
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


