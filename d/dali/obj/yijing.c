// Code of ShenZhou
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("���׾���", ({ "yi jing", "book" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("material", "paper");
               set("value", 500);
        }
        setup();
}

