// Code of ShenZhou
// peanut.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ˮ����", ({"huasheng", "peanut"}));
        set_weight(60);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������ˮ�����ס�\n");
                set("unit", "��");
                set("value", 15);
                set("food_remaining", 1);
                set("food_supply", 30);
        }
}
