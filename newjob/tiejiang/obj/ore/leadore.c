// 铅空矿石
// tinore.c
// Code by Cheap
// 2001/10/25
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("铅空矿石", ({"lead ore"," kuang"}));
	set_weight(32000);
        set_color("$HIB$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的铅空矿石，一种重而柔软，有延展性，可塑
性而没有弹性的 铅空矿矿石,一公斤大约可以提炼七八两的生铅坯出来。\n");
                set("unit", "斤");
                set("item_id", "lead");
set("material", "lead");
                set("basic_weight",100000);              
set("value",50);
set("ore", "/newjob/tiejiang/obj/ore/tinore.c");
set("strvalue", 19);
set("kuang", 1);
}

}
