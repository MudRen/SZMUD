//  /d/jueqing/obj/toufu.c ��ˮ����
//  jiuer---08/15/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"��ˮ����"NOR, ({"qingshui doufu", "doufu", "dou fu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ˮ������\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
