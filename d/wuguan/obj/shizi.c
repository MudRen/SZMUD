//Created by Zyu on k1-08-11
// Object: /d/wuguan/obj/shizi.c
#include <ansi.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;

void create()
{
	set_name(GRN"小石子"NOR, ({"xiao shizi", "shizi"}));

	if (clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "堆");
		set("base_unit","粒");
		set("long", "这是武馆里随处可见的小石子。\n");
		set("value", 0);
	}

	set_amount(1+random(2));
	set("no_get", "武馆财产，你可不能拿！\n");
	set("no_drop", "武馆赐予你的荣誉岂能丢掉！\n");

	setup();
}
