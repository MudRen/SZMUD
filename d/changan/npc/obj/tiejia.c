// Code of ShenZhou
// tiejia.c ����
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIC"����"NOR, ({ "armor" }) );
        set_weight(20000);
//***** ADDED BY SCATTER *****
                                set("wposition", "/d/city/npc/obj/tiejia.c");
//***** END OF ADDING *****
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
		set("value", 2500);
                set("armor_prop/armor", 50);
        }
        setup();
}

