// Code of ShenZhou
#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(CYN"�಼��"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

