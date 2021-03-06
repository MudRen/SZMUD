// Code of ShenZhou
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "回回",
                "file"  :  "/d/quanzhou/npc/huihui",
                "where" :  "/d/quanzhou/qingjing",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  35,
                "score" :  4,
        ]),

        ([      "name"  :  "流氓头",
                "file"  :   "/d/city/npc/liumangtou",
                "where" :  "/d/city/guangchang",
                "area"  :   "扬州",
                "type"  :   "杀",
                "bonus" :	35,
         ]),  

         ([     "name"  :  "游方和尚",
                "file"  :   "/d/taishan/npc/seng-ren",
                "where" :  "/d/taishan/shijin",
                "area"  :   "泰山",
                "type"  :   "杀",
                "bonus" :	35,
               
         ]),   


        ([      "name"  :  "塘工",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "where" :  "/d/hangzhou/haidi",
                "area"  :  "杭州湾海堤",
                "type"  :  "杀",
                "bonus" :  35,
                "score" :  3,
        ]),

        
        ([      "name"  : "家丁",
                "file"  :   "/d/taihu/npc/jiading",
                "where" :  "/d/taihu/damen",
                "area"  :   "归云庄",
                "type"  :   "杀",
                "bonus" :	38,
               
         ]),   


        ([      "name"  :  "天鹰教众",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "where" :  "/d/hangzhou/hsmiao",
                "area"  :  "杭州湾海神庙",
                "type"  :  "杀",
                "bonus" :  35,
                "score" :  5,
        ]),
        
         ([     "name"  :  "江湖豪客",
                "file"  :   "/d/huashan/npc/haoke",
                "where" :  "/d/huashan/qingke",
                "area"  :   "华山",
                "type"  :   "杀",
                "bonus" :	35,
         ]),   


        ([      "name"  :  "蝎子壳",
                "file"  :  "/d/xingxiu/npc/scorp_shell",
                "type"  :  "寻",
                "bonus" :  20,
        ]),

        ([      "name"  :  "蜈蚣壳",
                "file"  :  "/d/xingxiu/npc/wg_shell",
                "type"  :  "寻",
                "bonus" :  20,
	]),

        ([      "name"  :  "毒蛛丝",
                "file"  :  "/d/xingxiu/npc/zhusi",
                "type"  :  "寻",
                "bonus" :  20,
        ]),

        ([      "name"  :  "沙虫壳",
                "file"  :  "/d/xingxiu/npc/shachongke",
                "type"  :  "寻",
                "bonus" :  20,
        ]),
       
	([	"name" : "羊鞭", 
		"file" : "d/xingxiu/npc/obj/bian.c", 
		"type" : "寻", 
		"bonus" :  20,
	]),
	
	([	"name" : "青布缁衣",
		"file" : "/d/emei/npc/obj/nun-cloth.c", 
		"type" : "寻" ,
		"bonus" :  15,
	]),
	
	([	"name" : "狐狸皮" ,
		"file" : "clone/drug/hulipi", 
		"type" : "寻" ,
		"bonus" :  30,
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
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
        ]),
        
        ([      "type"  :  "伙计",
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
        
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


