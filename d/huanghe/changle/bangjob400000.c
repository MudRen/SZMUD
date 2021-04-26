// Code of ShenZhou
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([     "name"  :  "Â½¸ßÖ¹",
                "file"  :   "/d/city/npc/gaozhi",
                "where" :  "/d/city/ymzhengting",
                "area"  :   "ÑïÖÝ",
                "type"  :   "É±",
                "bonus" :	32,
               
         ]),  

        ([      "name"  :  "ëøÒ»À×",
                "file"  :  "/d/changbai/npc/teng",
                "where" :  "/d/changbai/nancheng",
                "area"  :  "¹Ø¶«",
                "type"  :  "É±",
                "bonus" :  32,
        ]),
        
        ([      "name"  :  "ÓàÓãÍ¬",
                "file"  :   "/d/city/npc/yutong",
                "where" :  "/d/city/neizhai",
                "area"  :   "ÑïÖÝ",
                "type"  :   "É±",
                "bonus" :	32,
              
         ]),
         
        ([      "name"  : "·ëÌú½³",
                "file"  :   "/d/village/npc/smith",
                "where" :  "/d/village/smithy1",
                "area"  :   "»ªÉ½´å",
                "type"  :   "É±",
                "bonus" :	30,
         ]),   

         ([     "name"  :  "Ò»Æ·ÌÃÎäÊ¿",
                "file"  :   "/d/xixia/npc/ypshi",
                "where" :  "/d/xixia/ypgate",
                "area"  :   "Î÷ÏÄ",
                "type"  :   "É±",
                "bonus" :	30,
         ]),   

 

	([      "name"  :   "ÕªÐÇ×Ó",
                "file"  :   "/kungfu/class/xingxiu/zhaixing",
                "where" :  "/d/xingxiu/cave",
                "area"  :   "ÐÇËÞ",
                "type"  :   "É±",
                "bonus" :	32,
         ]),    
         
/*
         ([     "name"  :  "´Þ°ÙÈª",
                "file"  :   "/d/dali/npc/cui",
                "where" :  "/d/dali/wangfu2",
                "area"  :   "´óÀí",
                "type"  :   "É±",
                "bonus" :	32,
         ]),      
*/


        ([      "name"  :  "ÈË²Î",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  15,
        ]),
        
/*
        ([      "name" : "ÈË²Î¹û" ,
		"file" : "/clone/wiz/renshen_guo2", 
		"type" : "Ñ°" ,
		"bonus": 25,
	]),
*/

                  ([      "name" : "òþÉßµ¨" ,  
                          "file" : "/clone/drug/mangshe-dan",   
                          "type" : "Ñ°" ,  
                          "bonus": 30, 
                  ]),  


	
	([	"name" : "¸Ö×¦" ,
		"file" : "/d/xixia/obj/gangzhua.c", 
		"type" : "Ñ°" ,
		"bonus": 20,
	]),

	
	([	"name" : "Çà¸Õ½£" ,
		"file" : "clone/weapon/qinggang-jian", 
		"type" : "Ñ°" ,
		"bonus":15,
	]),
	
/*
	([	"name" : "ÁøÒ¶µ¶" ,
		"file" : "/d/xixia/obj/liuyedao.c", 
		"type" : "Ñ°" ,
		"bonus": 18,
	]),
*/

	([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        ([      "type"  :  "ËÍÀñ",
        ]),
        
        
        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        
        ([      "type"  :  "Ì¯·Ñ",
        ]),
        

        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),

});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
