// lingzhi.c 千年灵芝
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
	set_name(HIR"万年灵芝"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的万年灵芝，据说吃一棵可得3000经验，1000潜能。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
      object me=this_player();
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("combat_exp", 3000);
	this_player()->add("potential",1000);
        this_player()->set("eff_jing", (int)me->query("max_jing"));
        this_player()->set("jing", (int)me->query("max_jing"));
        this_player()->set("eff_qi", (int)me->query("max_qi"));
        this_player()->set("jingli", (int)me->query("max_jingli"));
        this_player()->set("qi", (int)me->query("max_qi"));
        this_player()->set("neili", (int)me->query("max_neili"));
	message_vision("$N吃下一棵万年灵芝，感到浑身舒畅!\n", this_player());
	this_player()->add("story/lingzhi",1);
	destruct(this_object());
	return 1;
}

