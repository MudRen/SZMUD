// /d/jueqing/obj/miguo.c
// Jiuer 9/18/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"������"NOR, ({"mi sanguo","guo"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɽ髣����ӣ��׹����𻨽��ͷ����Ƴɵ�������ġ�\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}

