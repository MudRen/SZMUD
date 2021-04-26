// chisel.c

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("开山凿", ({ "chisel", "zao" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一把铁制开山长凿，掂在手里沉沉的。\n");
		set("value", 300);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_stick(15);
	setup();
}
