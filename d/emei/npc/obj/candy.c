// Code of ShenZhou
// candy.c ϲ��
// Shan: 96/08/14

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ϲ��", ({"candy", "xi tang", "tang"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "һ�Ű��ź�ֽ��ϲ�ǡ�\n");
                set("unit", "��");
                set("value", 2);
                set("food_remaining", 2);
                set("food_supply", 1);
        }
}

