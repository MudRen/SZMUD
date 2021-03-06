/*-------------------------------------------------------------
** 文件名: qianceng-xue.c
** Copyright (c) 2000-2001
** 创建人: 叶枫
** 日  期: 2001/08/13
** 描  述: 千层雪
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"千层雪"NOR, ({"qianceng xue", "xue", "bingqiling"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("s_name","千层雪");
		set("long", "这是一盒和路雪出品的千层雪。\n");
		set("unit", "盒");
		set("value", 100);
		set("remaining", 20);
		set("food_supply", 10);
		set("drink_supply", 10);
	}

	setup();
}

void init()
{
	add_action("do_drink", "eat");
}

int do_drink(string arg)
{
	if (arg!="qianceng xue" && arg!="xue" && arg!="bingqiling") return 0;
	if (this_player()->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");

	if ((int)this_player()->query("water")
		>= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");
	if ((int)this_player()->query("food")
		>= (int)this_player()->max_food_capacity() )
		return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));
	this_player()->add("food", (int)query("food_supply"));

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if (query("remaining")) {
		message_vision("$N用小勺舀出一勺冰淇淋，吃了一口，只觉冰凉可口。\n",this_player());
	}
	else {
		message_vision("$N用小勺舀出最后一点冰淇淋，吃了下去。\n",this_player());
		destruct(this_object());
	}
	return 1;
}

