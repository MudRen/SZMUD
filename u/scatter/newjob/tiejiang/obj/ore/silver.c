// 银矿石
// silverore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("银矿石", ({"silver ore","yin kuang"}));
      set_weight(41000);

        set_color("$HIW$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的脆银矿石，有延展性和良
好的韧性。这种脆银矿矿石,一公斤大约可以提炼七八两的生银坯出来。\n");
                set("unit", "斤");
                set("item_id", "silver");
set("material", "silver");
set("value",1000);
set("ore", "/newjob/tiejiang/obj/ore/silver.c");
                set("basci_unit","两"); 
                set("basic_value", "10000000");  
set("strvalue", 15);
set("kuang", 1);          
        }

}
