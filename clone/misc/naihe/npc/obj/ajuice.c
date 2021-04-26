// 苹果汁，拿来给我的NPC卖的。    ★/npc/obj/ajuice.c
// by naihe  2002-04-29

inherit ITEM;
#include <ansi.h>

int remaining=(4+random(3));

void create()
{
	set_name(HIG"苹果汁"NOR, ({"apple juice", "juice"}));

	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "一杯清甜的苹果汁。\n");
		set("unit", "杯");
		set("value", 300);
		set("drink_supply", 30);
	}
	setup();
}

void init()
{
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

int do_food(string arg)
{
	object me=this_player();

	if (arg!="apple juice" && arg!="ajuice")
	return 0;

	if (me->is_busy())
	return notify_fail("慢慢喝，别急。\n");

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
		message_vision("$N喝下一口苹果汁，觉得清爽怡人。\n",me);
	}

	else
	{
		message_vision("$N把剩下的苹果汁一口喝得干干净净。\n",me);

	destruct(this_object());
	}
	return 1;
}
