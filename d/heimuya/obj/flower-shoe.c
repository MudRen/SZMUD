// Code of ShenZhou
// flower-shoe.c
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "�廨Ь", ({ "flower shoes", "shoes"}) );
        set_color("$HIM$");
        set("long", "����һ˫������ϸ�ĺ�ɫ�廨Ь��\n");
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "˫");
                set("value", 1000);
                set("armor_prop/armor", 1 );
                set("female_only", 1);
        }
        setup();
}
