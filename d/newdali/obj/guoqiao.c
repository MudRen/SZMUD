// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"���ź���"NOR, ({"guoqiao heiyu", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�������ϵ����˹��ź��㡣\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}

