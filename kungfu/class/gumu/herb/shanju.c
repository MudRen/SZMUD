// 山菊 chaihu.c
// by april 2001.11.09

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(YEL"山菊"NOR, ({"shanju"}));
	set_weight(5);
	if (clonep()) set_default_object(__FILE__);
	else {
		set("unit", "两");
		set("long","终南山上的山菊，药材，清火。\n");
		set("value", 120);
		set("yaocai", 1);
		set("cure_s",1);
		set("cure_d",3);
		set("cure_n",1);
	}
	setup();
}