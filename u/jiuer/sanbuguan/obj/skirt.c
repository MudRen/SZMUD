// purplequn.c
// jiuer: 05/23/2002

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"红罗裙"NOR, ({ "skirt", "qun"}) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条红色长裙，裙腰上有条暗红色袢带。\n");
		set("unit", "件");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

