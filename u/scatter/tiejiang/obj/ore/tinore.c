// 锡矿石
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("锡矿石", ({"tin ore","xi kuang"}));
set_weight(35000);
        set_color("$BLU$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的锡矿石，脆弱容易断。
。这种青铜矿矿石,一公斤大约可提炼七八两的生铜坯出来。\n");
                set("unit", "斤");
                set("item_id", "tin");
set("material", "tin");
set("value",60);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 22);
set("kuang", 1);
        }

}
