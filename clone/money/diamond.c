// Code of ShenZhou
// gold.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name("钻石", ({"diamond", "zuan", "zuan_money"}));
        set_color("$HIW$");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "diamond");
		set("long", "这就是世界上最值钱的东西——钻石了，许多人一辈子都没见过。\n许多人将它当作钱币来使用。\n");
		set("unit", "些");
		set("base_value", 1000000 );
		set("base_unit", "颗");
		set("base_weight", 20);
	}
	set_amount(1);
}

