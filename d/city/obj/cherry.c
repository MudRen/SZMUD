// Code of ShenZhou
// cherry.c ӣ��

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"ӣ��"NOR, ({"ying tao", "cherry"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ�����ʣ����޿��˵�ӣ�ҡ�\n");
		set("unit", "��");
		set("value", 60);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
