// Code of ShenZhou
// pear ��ɽѼ��
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ѽ��", ({"ya li", "li", "pear"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������Ѽ�档\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 2);
		set("food_supply", 15);
	}
}
