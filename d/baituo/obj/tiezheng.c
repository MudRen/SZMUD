// by Jiuer
// guzhen.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIW"铁筝"NOR,({ "tie zheng", "zheng" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 5000);
		set("material", "steel");
        set("shape", "zither");
		set("long", "这是一张西域铁铮，精工细制而成。\n");
		set("wield_msg", "$N操起一张$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_staff(7);
	setup();
}
