// Code of ShenZhou
// mitao.c ˮ����
// By Marz

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"ˮ����"NOR, ({"tao", "mi tao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˮ�����ʵ�ˮ���ң���С���������һ�����޿��ˡ�\n");
		set("unit", "ֻ");
		set("value", 60);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
