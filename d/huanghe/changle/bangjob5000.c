// Code of ShenZhou
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "»Ø»Ø",
                "file"  :  "/d/quanzhou/npc/huihui",
                "where" :  "/d/quanzhou/qingjing",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  35,
                "score" :  4,
        ]),

        ([      "name"  :  "Á÷Ã¥Í·",
                "file"  :   "/d/city/npc/liumangtou",
                "where" :  "/d/city/guangchang",
                "area"  :   "ÑïÖÝ",
                "type"  :   "É±",
                "bonus" :	35,
         ]),  

         ([     "name"  :  "ÓÎ·½ºÍÉÐ",
                "file"  :   "/d/taishan/npc/seng-ren",
                "where" :  "/d/taishan/shijin",
                "area"  :   "Ì©É½",
                "type"  :   "É±",
                "bonus" :	35,
               
         ]),   


        ([      "name"  :  "ÌÁ¹¤",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "where" :  "/d/hangzhou/haidi",
                "area"  :  "º¼ÖÝÍåº£µÌ",
                "type"  :  "É±",
                "bonus" :  35,
                "score" :  3,
        ]),

        
        ([      "name"  : "¼Ò¶¡",
                "file"  :   "/d/taihu/npc/jiading",
                "where" :  "/d/taihu/damen",
                "area"  :   "¹éÔÆ×¯",
                "type"  :   "É±",
                "bonus" :	38,
               
         ]),   


        ([      "name"  :  "ÌìÓ¥½ÌÖÚ",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "where" :  "/d/hangzhou/hsmiao",
                "area"  :  "º¼ÖÝÍåº£ÉñÃí",
                "type"  :  "É±",
                "bonus" :  35,
                "score" :  5,
        ]),
        
         ([     "name"  :  "½­ºþºÀ¿Í",
                "file"  :   "/d/huashan/npc/haoke",
                "where" :  "/d/huashan/qingke",
                "area"  :   "»ªÉ½",
                "type"  :   "É±",
                "bonus" :	35,
         ]),   


        ([      "name"  :  "Ð«×Ó¿Ç",
                "file"  :  "/d/xingxiu/npc/scorp_shell",
                "type"  :  "Ñ°",
                "bonus" :  20,
        ]),

        ([      "name"  :  "òÚò¼¿Ç",
                "file"  :  "/d/xingxiu/npc/wg_shell",
                "type"  :  "Ñ°",
                "bonus" :  20,
	]),

        ([      "name"  :  "¶¾ÖëË¿",
                "file"  :  "/d/xingxiu/npc/zhusi",
                "type"  :  "Ñ°",
                "bonus" :  20,
        ]),

        ([      "name"  :  "É³³æ¿Ç",
                "file"  :  "/d/xingxiu/npc/shachongke",
                "type"  :  "Ñ°",
                "bonus" :  20,
        ]),
       
	([	"name" : "Ñò±Þ", 
		"file" : "d/xingxiu/npc/obj/bian.c", 
		"type" : "Ñ°", 
		"bonus" :  20,
	]),
	
	([	"name" : "Çà²¼ç»ÒÂ",
		"file" : "/d/emei/npc/obj/nun-cloth.c", 
		"type" : "Ñ°" ,
		"bonus" :  15,
	]),
	
	([	"name" : "ºüÀêÆ¤" ,
		"file" : "clone/drug/hulipi", 
		"type" : "Ñ°" ,
		"bonus" :  30,
	]),

        ([      "type"  :  "ÂòÂô",
        ]),

        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),

        ([      "type"  :  "ÂòÂô",
        ]),

        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),

	([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "ÂòÂô",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),

        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
        ]),
        
        ([      "type"  :  "»ï¼Æ",
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
        
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


