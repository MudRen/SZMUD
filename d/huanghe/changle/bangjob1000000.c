// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
       ([       "name"  :  "慕容博",
                "file"  :   "/clone/npc/murong",
                "where" :  "random",
                "area"  :   "附近走动",
                "type"  :   "杀",
                "bonus" :  35,

        ]),
        
        
        ([      "name"  :  "左冷禅",
                "file"  :   "/clone/npc/zuo",
                "where" :  "random",
                "area"  :   "附近走动",
                "type"  :   "杀",
                "bonus" :    35,
               
         ]),

        ([      "name"  : "李莫愁",
                "file"  :   "/kungfu/class/gumu/limochou",
                "where" :  "/d/jiaxing/nanhu",
                "area"  :   "嘉兴",
                "type"  :   "杀",
                "bonus" :	30,
         ]),
         
         ([     "name"  :   "玉真子",
                "file"  :   "/d/changbai/npc/yu",
                "where" :  "/d/changbai/muqiao",
                "area"  :   "长白",
                "type"  :   "杀",
                "bonus" :	30,
         ]),   
         
         ([     "name"  :   "萧远山",
                "file"  :   "/d/changbai/npc/xiao",
                "where" :  "/d/changbai/guandao1",
                "area"  :   "长白",
                "type"  :   "杀",
                "bonus" :	30,
         ]),   

        ([      "name"  :  "玄难大师",
                "file"  :   "/kungfu/class/shaolin/xuan-nan",
                "where" :  "/d/shaolin/banruo5",
                "area"  :   "少林",
                "type"  :   "杀",
                "bonus" :	30,
        ]),   

/*
	([      "name"  :   "张松溪",
                "file"  :   "/kungfu/class/wudang/xi",
                "where" :  "/d/wudang/hd_zoulang",
                "area"  :   "武当",
                "type"  :   "杀",
                "bonus" :	30,
         ]),   

       
       ([      "name" : "人参果" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "寻" ,
		"bonus": 25,
	]),
*/
             ([      "name" : "蟒蛇胆" , 
                      "file" : "/clone/drug/mangshe-dan",  
                      "type" : "寻" , 
                      "bonus": 30, 
              ]), 

	
	([	"name" : "鳄尾鞭" ,
		"file" : "/d/xixia/obj/eweibian.c", 
		"type" : "寻" ,
		"bonus": 15,
	]),

	([      "name"  :  "首乌精",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  15,
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
        

        ([      "type"  :  "买卖",
        ]),

});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
