// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(BLU"���"NOR, ({ "manao" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"����һ��������觡�\n");
                set("unit",  "��");
                set("value",  100);
                set("no_sell",  1);
                set("material", "silk");
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
