// Code of ShenZhou
// jiaohuaji.c ������

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"haoqiu tang", "soup"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����̵�������\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
