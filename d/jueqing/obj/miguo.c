// /d/jueqing/obj/miguo.c
// Jiuer 9/18/2001

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"蜜三果"NOR, ({"mi sanguo","guo"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘由山楂，栗子，白果，桂花酱和蜂蜜制成的甜果点心。\n");
                set("unit", "盘");
                set("value", 30);
                set("food_remaining", 3);
                set("food_supply", 20);
        }
}

