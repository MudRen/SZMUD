// /d/gumu/obj/pao.c 灰色长袍
// by April 01.08.04

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(WHT"灰色长袍"NOR, ({"pao", "cloth", "chang pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
                set("long", "一件普普通通的灰色长袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
