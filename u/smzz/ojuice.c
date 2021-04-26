// 橘子汁，拿来给我的NPC卖的。    ★/npc/obj/ojuice.c
// by naihe  2002-04-29

inherit ITEM;
#include <ansi.h>

int remaining=(4+random(3));

void create()
{
	set_name(HIY"橘子汁"NOR, ({"orange juice", "juice"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "一杯新鲜榨好的橘子汁。\n");
		set("unit", "杯");
		set("value", 300);
		set("drink_supply", 30);
	}
	setup();
}

void init()
{
	add_action("do_food", "drink");
	add_action("do_food", "drink");
}

int do_food(string arg)
{
	object me=this_player();

	if (arg!="orange juice" && arg!="ojuice")
	return 0;

	if (me->is_busy())
	return notify_fail("你上一个动作还没有完成。\n");

	if ((int)me->query("water") >= (int)me->max_water_capacity())
	return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");

	set("value", 0);
	me->add("water", (int)query("drink_supply"));
//	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(1);
	remaining-=1;

	if (remaining>0)
	{
		message_vision("$N喝下一口橘子汁，觉得味道鲜美极了。\n",me);
	}

	else
	{
		message_vision("$N把剩下的橘子汁一口喝得干干净净。\n",me);

	destruct(this_object());
	}
	return 1;
}
