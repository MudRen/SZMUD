//Cracked by jiuer
// /d/jueqing/obj/migao.c

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"情花米糕"NOR, ({"mi gao", "gao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一块由情花花瓣和穤米做成的香糕。\n");
                set("unit", "碗");
                set("value", 80);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}
