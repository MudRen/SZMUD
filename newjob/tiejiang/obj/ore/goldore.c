// 金矿石
// goldore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("金矿石", ({"gold ore","ore"}));

set_weight(50000);
        set_color("$HIY$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的金矿石，这种金矿矿石,一公斤大约可以提炼四五两的纯金出来。\n");
                set("unit", "斤");

                set("item_id", "gold");
set("value",10000);
set("material", "gold");
set("ore", "/newjob/tiejiang/obj/ore/goldore.c");
set("strvalue", 20);
set("kuang", 1);
        }

}
