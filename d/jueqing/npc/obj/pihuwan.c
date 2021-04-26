// pihuwan.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "牛皮护腕", ({ "hu wan", "huwan" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
                set("long", "这是一件皮质的护腕，用以保护腕部。\n");
		set("value", 250);
		set("material", "skin");
		set("armor_prop/armor", 5);
		set("jueqing",1);
	}
	setup();
}
