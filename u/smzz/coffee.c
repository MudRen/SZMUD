// 咖啡，拿来给我的NPC卖的。    ★/npc/obj/coffee.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=3;

void create()
{
	set_name(WHT"咖啡"NOR, ({"coffee","kafei"}));

	set_weight(180);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一杯香味浓郁的西洋饮品，名字叫做“咖啡”，听说那边的人都爱喝它。\n");
		set("unit", "杯");
		set("value", 1000);
		set("drink_supply", 100);
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
	
	if (arg!="coffee" && arg!="kafei")
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
		message_vision("$N端起一杯咖啡，细细地呷了一口。\n",me);
	}

	else
	{
		message_vision("$N端起咖啡，把最后一口喝了下去。\n",me);

	destruct(this_object());
	}
	return 1;
}
