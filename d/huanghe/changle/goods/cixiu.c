// Code of ShenZhou
// /d/huanghe/changle/obj/silk.c
// by aln  2 / 98

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED"����"NOR, ({ "cixiu" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"����һƥ�����壬һ����֪�ǳ��ڴ�ҹ���֮�֡�\n");
                set("unit",  "ƥ");
                set("value",  100);
                set("no_sell",  1);
                set("material", "silk");
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
