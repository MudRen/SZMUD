// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN"绸缎"NOR, ({ "silk" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"这是一匹做工极其考究的绸缎。\n");
                set("unit",  "匹");
                set("value",  100);
                set("no_sell",  1);
                set("material", "silk");
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
