// /d/jueqing/obj/noodle.c
// Jiuer 9/18/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�������"NOR, ({"la mian","noodle"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ư�����ʹ���ĩ�Ķ쵰�ֹ����棬����ѽ��\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

