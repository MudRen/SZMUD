// Code of ShenZhou
// hama.c

inherit NPC;

void create()
{
	set_name("莽牯朱蛤", ({"hama"}) );
	set("race", "野兽");
	set("age", 1000);
	set("long", "这是一只看起来非常奇怪的蛤蟆，体型巨大，全身通红。\n");
	set("str", 50);
	set("dex", 50);
	set("limbs", ({ "头部", "身体" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 50);

	setup();
}
