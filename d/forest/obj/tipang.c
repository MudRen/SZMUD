// Code of ShenZhou

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("±�����", ({"tipang", "ti"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��±�����\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
