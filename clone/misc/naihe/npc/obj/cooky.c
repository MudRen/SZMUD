// 曲奇饼，拿来给我的NPC卖的。    ★/npc/obj/cooky.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=(3+random(4));

void create()
{
	set_name(HIY"曲奇饼"NOR, ({"cooky","bing" ,"bing gan"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "一小碟饼干，大概有5、6个，挺松脆的模样。\n");
		set("unit", "碟");
		set("value", 100);
		set("food_supply", 20);
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

	if (arg!="cooky" && arg!="bing" && arg!="bing gan")
	return 0;

	if (me->is_busy())
	return notify_fail("你上一个动作还没有完成。\n");

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
		message_vision("$N从碟子里拿起一块曲奇饼吃了下去。\n",me);
	}

	else
	{
		message_vision("$N拿起碟子里的最后一块曲奇饼，十分不舍地吃了下去。\n",me);
		destruct(this_object());
	}
	return 1;
}
