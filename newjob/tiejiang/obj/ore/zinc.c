// 锌矿石
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("锌矿石", ({"zinc ore","xin kuang"}));
	set_weight(37800);
        set_color("$HIB$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的锌矿石，一公斤大约可以提炼七八两的生锌坯出来。\n");
                set("unit", "斤");
                set("item_id", "zinc");
set("material", "zinc");
set("value",100);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 14);
set("kuang", 1);
        }

}
