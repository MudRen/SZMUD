#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("铁矿石", ({"iron ore","tie kuang"}));
set_weight(450000);


        set_color("$HIW$");
        if( clonep() )set_default_object(__FILE__);
        else {
set ("long", " 这是一块刚刚开采的菱铁矿矿石，含铁量相当丰富,坚硬的沉积岩。这种菱铁矿矿石,一公斤大约可以提炼半公斤的生铁坯出来。\n");

set("unit", "斤");


                set("item_id", "iron");
set("material", "iron");
set("value",45);
set("ore", "/newjob/tiejiang/obj/ore/ironore.c");
set("strvalue", 16);
set("kuang", 1);
setup();
}





setup();

        }
