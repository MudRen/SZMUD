// Code by Scatter
// barmor.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG"����"NOR, ({ "armor" }) );
        set_weight(20000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
                set("value", 4000);
                set("armor_prop/armor", 90);
        }
        setup();
}