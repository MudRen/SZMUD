// 铝矿石
// aluminiumore.c
// Code by Cheap
// 2001/10/24
// V. 1.0

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(" 铝矿石", ({"aluminium","jin kuang"}));
        set_weight(37000);
        set_color("$YEL$");
        if( clonep() )set_default_object(__FILE__);
        else {
                set("long", "这是一块刚刚开采的 铝矿石，延展性好和有韧性
。这种青铜矿矿石,一公斤大约可以提炼七八两的生铝坯出来。\n");
                set("unit", "斤");
                set("item_id", "aluminium");
set("material", "aluminium");
set("value", 40);
set("ore","/newjob/tiejiang/obj/ore/aluminiumore.c");
set("strvalue", 16);
set("kuang", 1);
        }

}
