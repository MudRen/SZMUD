// 目录: 木工/木匠
// saw.c 锯子

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("大龙锯", ({ "saw","ju zi", "ju" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把双人合用的大龙锯，可以用来锯树木的。\n");
		set("value", 1000);
		set("material", "steel");
               // set("no_drop",1);
	}
	init_axe(10);
	setup();
}

