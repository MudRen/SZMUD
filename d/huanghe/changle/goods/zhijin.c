// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"����֯��"NOR, ({ "zhijin" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"����һƥ�ϵȵĺ���֯����\n");
                set("unit",  "ƥ");
                set("material", "silk");
                set("no_sell",  1);
                set("value",  100);
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
