// Code of ShenZhou
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("¡ºÒ×¾­¡»", ({ "yi jing", "book" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "²á");
		set("material", "paper");
               set("value", 500);
        }
        setup();
}

