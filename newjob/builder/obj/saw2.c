// 目录: 木工/木匠
// saw2.c 手锯

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("手锯", ({ "saw","ju zi", "ju" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把手锯，可以用来锯木头的。\n");
		set("value", 1000);
		set("material", "steel");
		set("no_drop",1);
	}
	init_axe(10);
	setup();
}
