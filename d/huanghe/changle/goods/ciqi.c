// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"����"NOR, ({ "china","ciqi" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"����һ�׽����Ͼ�Ĵ�����һ����֪���ϵȻ���\n");
                set("unit",  "��");
                set("value",  100);
                set("no_sell",  1);
                set("material", "silk");
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
