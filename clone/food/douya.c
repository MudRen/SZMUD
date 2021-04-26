// /d/jueqing/obj/douya.c ËØ³´¶¹Ñ¿
// jiuer -- 08/15/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"ËØ³´¶¹Ñ¿"NOR, ({"suchao douya", "dou ya", "douya"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Åè»Æ°×Ïà¼ä£¬ÇåÏã¿É¿ÚµÄËØ³´»Æ¶¹Ñ¿¡£\n");
		set("unit", "Åè");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
