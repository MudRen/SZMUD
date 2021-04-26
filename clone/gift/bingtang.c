// lingzhi.c 冰糖葫芦
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIM"冰糖葫芦"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("long", "这是一用多味奇果精心制作而成的冰糖葫芦，据说吃一棵可得3000经验，1000潜能。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("combat_exp", 3000);
	this_player()->add("potential",1000);
	message_vision("$N吃下一串冰糖葫芦，感觉功力大进 !\n", this_player());
	this_player()->add("story/hulu", 1);
	destruct(this_object());
	return 1;
}

