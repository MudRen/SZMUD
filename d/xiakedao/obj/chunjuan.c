//Cracked by Roath
// chunjuan.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"chun juan", "eggroll"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ը�Ľ�ƵĴ���\n");
                set("unit", "��");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
