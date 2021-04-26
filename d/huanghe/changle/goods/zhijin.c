// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"杭州织锦"NOR, ({ "zhijin" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"这是一匹上等的杭州织锦。\n");
                set("unit",  "匹");
                set("material", "silk");
                set("no_sell",  1);
                set("value",  100);
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
