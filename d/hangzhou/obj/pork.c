// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"������"NOR, ({"pork"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
