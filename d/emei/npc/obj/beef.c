// Code of ShenZhou
// /d/emei/npc/obj/niurou.c ţ��
// Shan: 96/07/09

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ţ��", ({"niu rou", "beef", "rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "һ�鿾���������ţ�⡣\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}

