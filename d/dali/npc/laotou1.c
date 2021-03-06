// Code of ShenZhou
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("牢头", ({ "lao tou", "tou", "guard" }) );
        set("gender", "男性");
        set("age", 35);
        set("long",
                
"这位是大理国的牢头，只见他身着竹甲，脚蹬草履，腰上挂着一大串铁钥匙。\n"
"也许由于酒色过多，他满眼血丝，足下不稳。\n");
        set("combat_exp", 60000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 22);
        set("int", 20);
        set("dex", 24);

        set("max_qi", 600);
        set("eff_qi", 600);
        set("qi", 600);
        set("max_jing", 500);
        set("jing", 500);
        set("neili", 400);
        set("max_neili", 600);
        set("jiali", 20);
        set("shen_type", 0);

        set_temp("apply/attack",  30);
        set_temp("apply/defense", 30);

        set_skill("blade", 60);
        set_skill("unarmed", 50);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	
   set("no_get", "你疯了，王府前就敢抢人? 别忘了天龙寺的和尚们杀人不眨眼");

        setup();

        carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/dali/obj/jcloth")->wear();
}
