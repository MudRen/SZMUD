// Code of ShenZhou
// goupi.c
//
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"��Ƥ"NOR, ({ "gou pi", "pi" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/goupi.c");
//***** END OF ADDING *****
                set("material", "fur");
		set("value", 100);
                set("armor_prop/armor", 1);
        }
        setup();
}

