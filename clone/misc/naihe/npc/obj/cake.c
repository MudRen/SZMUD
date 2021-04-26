// 小蛋糕，拿来给我的NPC卖的。    ★/npc/obj/cake.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=3;

void create()
{
	set_name(HIC"小蛋糕"NOR, ({"cake","dan gao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一个半巴掌大的小蛋糕，顶上还嵌着颗小樱桃，看起来味道不错。\n");
		set("unit", "个");
		set("value", 80);
		set("food_supply", 30);
	}
	setup();
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "eatt");
}

int do_food(string arg)
{
	object me=this_player();

	if (arg != "cake" && arg != "dan gao")
	return 0;

	if (me->is_busy())
	return notify_fail("慢慢吃，别急。\n");

//	if ((int)me->query("water") >= (int)me->max_water_capacity())
//	return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");

	if ((int)me->query("food") >= (int)me->max_food_capacity())
	return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");

	set("value", 0);
//	me->add("water", (int)query("drink_supply"));
	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(1);
	remaining-=1;

	if (remaining>0)
		{
			message_vision("$N拿起小蛋糕咬了一口，觉得味道还真不错。\n",me);
		}

	else
		{
			message_vision("$N把剩下的小蛋糕一口吃了下去，真是回味无穷！\n",me);
			destruct(this_object());
		}
	return 1;
}
