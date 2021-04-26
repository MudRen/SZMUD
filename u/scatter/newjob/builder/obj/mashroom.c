// mashroom Ä¢¹½

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ä¢¹½", ({"mo gu", "mashroom" }));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Ö»»Ò°×É«Ð¡Ä¢¹½¡£\n");
		set("unit", "Ö»");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}
