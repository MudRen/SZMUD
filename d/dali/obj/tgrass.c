// Code of ShenZhou
// tgrass.c 通天草

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name( GRN "通天草" NOR , ({"tongtian cao", "grass"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("material", "grass");
		set("long", "这是一株看起来很普通的小草，但其实只产于云南无量山地区，有镇痛解毒的奇效。\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (arg!="grass") return 0;


	message_vision(HIY "$N吃下一株通天草，脸上的黑气褪下了一些。\n" NOR, me);

	destruct(this_object());
	return 1;
}
