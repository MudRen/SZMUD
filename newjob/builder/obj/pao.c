// /newjob/builder/pao.c 黑色长袍
// by jiuer 11/2001

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("黑色长袍", ({"pao", "cloth", "chang pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件普普通通的黑色长袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
