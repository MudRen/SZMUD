//Cracked by jiuer
// /d/jueqing/obj/huaban.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"�黨����"NOR, ({"hua ban", "huaban"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���黨���ꡣ\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}
