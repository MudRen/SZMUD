// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(BLU"Ҷ����"NOR, ({"ye er ba", "cake"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��Ʈ�������Ҷ���Ρ�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}






