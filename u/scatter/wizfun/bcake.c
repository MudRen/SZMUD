 // Code of ShenZhou
// kaoya.c ��Ѽ

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void init();

void create()
{
        set_name(HIY"�˾���21������յ���"NOR, ({"mod cake", "cake"}));

        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һƬ�˾���21������յ��⡣\n");
                set("unit", "Ƭ");
                set("value", 120);
                set("food_remaining", 3);
                set("food_supply", 80);
        }

        setup();
}
