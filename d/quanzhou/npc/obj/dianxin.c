// Code of ShenZhou
// dianxin.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"dian xin", "dianxin"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������Ȫ�ݵ��ز�����ʽ�ڶ࣬��ζ�ɿڡ�\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}

