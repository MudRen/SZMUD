// jiuer -- 9/20/2001
// jianbing.c ���ͼ��

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���ͼ��", ({"jian bing", "pancake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����潹��Ĺ�����С�����\n");
                set("unit", "��");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
