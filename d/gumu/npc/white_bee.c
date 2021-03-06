// white_bee.c	玉蜂群
// by April 01.09.01

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(WHT"玉蜂群"NOR, ({ "bees" }) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 1);
	set("long", "这是古墓派驯养的一群玉蜂，嗡嗡的，不只有多少。\n");
	set("str", 60);
	set("dex", 80);

	set("limbs", ({ "密集处", "稀薄处", "核心", "外围" }) );

	set("max_jing",1000);
	set("jing",1000);
	set("qi",1000);
	set("max_qi",1000);
	set("jingli",1000);
	set("max_jingli",1000);

	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);

	setup();
}

/*
void unconcious()
{
        object ob;

        if( base_name(environment(this_object())) == "/d/dali/chhill4" && random(6) > 0 ) {
                 ob = new(__FILE__);
                 ob->move(environment());
        	 message_vision("\n嗡，嗡，嗡，又飞来一只毒蜂。\n", this_object());
        } else {
                 message_vision("\n一阵风把死蜂吹走了。\n", this_object());
        }

        destruct(this_object());
}
*/

void die()
{
	object ob;

	message_vision("\n$N终于都死了，地上白茫茫一片。\n", this_object());
	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("yufeng_poison", 5 + random(5) +
		victim->query_condition("yufeng_poison"));
}

