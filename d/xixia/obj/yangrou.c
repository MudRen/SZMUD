// Code of ShenZhou
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("??????", ({"kao yangtui", "yangtui","yang","tui"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ???????????????ȡ?\n");
		set("unit", "ֻ");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
