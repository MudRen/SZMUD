// Code of ShenZhou

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( YEL"Ƥ????"NOR, ({ "pi beixin", "beixin" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "??");
                set("value", 300);
                set("material", "leather");
                set("armor_prop/armor", 6);
        }
        setup();
}

