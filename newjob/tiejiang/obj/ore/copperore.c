// 铜矿石
// silverore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("铜矿石", ({"copper ore","tong kuang"}));
        set_weight(30000);
        set_color("$YEL$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的青铜矿石，有延展性和展性
。这种青铜矿矿石,一公斤大约可以提炼七八两的生铜坯出来。\n");
                set("unit", "斤");
                set("item_id", "copper");
set("ore", "/newjob/tiejiang/obj/ore/copperore.c");
set("material", "copper");
set("value", 45);
set("strvalue", 14);
set("kuang", 1);
        }

}
