// Code of ShenZhou

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("¹��", ({"lu rou", "rou"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ѫ����ʵ�¹�⡣\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 8);
		set("food_supply", 50);
//		set("food_race","Ұ��");
	}
}
