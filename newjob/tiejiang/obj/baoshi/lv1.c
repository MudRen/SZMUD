#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIB "绿宝石" NOR, ({ "lv baoshi", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一颗普通的绿宝石。\n");
                set("value", 1000);
                set("material", "leather");
        }
        setup();
}
