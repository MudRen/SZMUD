// Code of ShenZhou
// green_beixin.c �����������

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "�����������", ({ "qing beixin", "beixin" }) );
	set_color(GRN);
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

