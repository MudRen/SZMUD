// Code of ShenZhou
// maco

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"grape", "putao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����³�����������ѣ��ſ����̾����������㡣\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 6);
		set("food_supply", 10);
		set("eat_msg","$N�����˼������ѡ�");
	}
}
