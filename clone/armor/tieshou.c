// Code of ShenZhou
// tieshou.c

#include <armor.h>

inherit HANDS;

void create()
{
	set_name( "Ã˙ ÷’∆", ({ "iron hand", "hand" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "øÈ");
		set("value", 50);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/tieshou.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 1 );
	}
	setup();
}
