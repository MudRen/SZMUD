//Cracked by Roath
// jianbing.c ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({"jian bing", "pancake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ļ����\n");
                set("unit", "��");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
