#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIY "非洲之星" NOR, ({ "feizhou zhixing", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIC"这是世间罕见的珍贵宝石。\n"NOR);
                set("value", 10000);
                set("material", "leather");
        }
        setup();
}
