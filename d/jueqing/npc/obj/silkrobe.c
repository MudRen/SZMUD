// Filename: /d/jueqing/obj/silkrobe.c
// Jiuer--Aug 11.2001


#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	    set_name(BLU"缎袍"NOR, ({ "skillrobe", "cloth", "pao", "robe"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件宝蓝色缎子长袍。\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 0);
        }
        setup();
}
