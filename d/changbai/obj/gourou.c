// Code of ShenZhou
// gourou

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("����", ({"gou rou", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "����һ��������Ĺ��⡣\n");
        set("unit", "��");
	set("value", 100);
	set("food_remaining", 3);
	set("food_supply", 80);
	}
}
