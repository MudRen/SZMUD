// /d/jueqing/obj/douya.c �س���ѿ
// jiuer -- 08/15/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"�س���ѿ"NOR, ({"suchao douya", "dou ya", "douya"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ư���䣬����ɿڵ��س��ƶ�ѿ��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
