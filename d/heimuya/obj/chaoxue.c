// Code of ShenZhou
// chaoxue.c
// fear: 1999/12/08

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name("��ѥ", ({ "chao xue", "boots", "shoes"}) );
        set_color("$HIC$");
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long",  "����һ˫��з۵׳�ѥ��\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 2);
        }

}
