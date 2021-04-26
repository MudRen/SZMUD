// jitui.c 鸡腿
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸡腿", ({ "jitui", "tui" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根吃得剩半边的烤鸡腿。\n");
		set("unit", "根");
		set("value", 0);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
	setup();
}

int finish_eat()
{
	set_name("啃得精光的鸡腿骨头", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的鸡腿骨头。\n");
	return 1;
}
