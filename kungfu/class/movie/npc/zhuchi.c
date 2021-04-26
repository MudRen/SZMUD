#include <ansi.h>
inherit NPC;


void create()
{
        set_name("主持人", ({ "zhuchi","zhu chi" }));
        set("title","有奖竞答活动");
        set("long", "一个满面微笑，风度翩翩的主持人。\n");
        set("gender", "男性");
        set("age", 25);
        set("max_jing", 200);
        set("max_qi", 200);
        
        set("combat_exp", 10000);
        set("shen_type", 1);
        
        set("inquiry", ([
                "有奖竞答" : "有奖竞答会在影片播放的中途进行。\n",
                "彩票" : "彩票是扬州彩票行发行的。如果你得到彩票奖品请放进皮囊里保管好。\n",
                "皮囊" : "皮囊可以到扬州彩票行去领取，领取以后就可以永远带在身上。\n",
        ]));
        
        setup();
}




