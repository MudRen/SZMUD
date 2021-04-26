// Code of ShenZhou
// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( WHT"������"NOR, ({ "tie beixin", "beixin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "iron");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/tie-beixin.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 15);
		set("shaolin",1);
	}
	setup();
}
