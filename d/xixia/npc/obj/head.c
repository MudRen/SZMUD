// Code of ShenZhou
// 

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ͷ", ({"head", "rentou", "tou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
	}

	setup();
}

