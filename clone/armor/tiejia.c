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
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");

//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/tiejia.c");
//***** END OF ADDING *****

		set("value", 2500);
                set("armor_prop/armor", 50);
        }
        setup();
}

