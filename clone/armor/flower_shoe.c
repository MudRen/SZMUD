// Code of ShenZhou
// shoe.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( MAG"�廨СЬ"NOR, ({ "flower shoes", "shoes"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("value", 100);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/flower_shoe.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
