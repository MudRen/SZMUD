// Code of ShenZhou
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("信物", ({"xinwu"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                
set("long","这是王语嫣身上的信物。\n");
            
               set("no_get", "这东西你偷不到。\n");
                set("material", "paper");
        }
}







