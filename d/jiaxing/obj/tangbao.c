// Code of ShenZhou
// tangbao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"tang bao", "bao"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������Ȫ�ݵ��ز���\n");
                set("unit", "��");
                set("value", 45);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

