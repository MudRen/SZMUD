// Code of ShenZhou
// 

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("»ÀÕ∑", ({"head", "rentou", "tou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ø≈");
		set("value", 0);
	}

	setup();
}

