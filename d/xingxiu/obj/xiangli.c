// Code of ShenZhou
// maco

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"xiang li", "li"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ճ��������棬���ʵ��ִࡢ֭����㡢��ϸζ���������\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 15);
	}
}
