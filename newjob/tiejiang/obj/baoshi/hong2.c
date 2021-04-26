#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIR "红宝石" NOR, ({ "hong baoshi", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一颗稀有的红宝石。\n");
                set("value", 3000);
                set("material", "leather");
        }
        setup();
}
