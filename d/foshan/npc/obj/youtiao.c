// Code of ShenZhou
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"youtiao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���͹���������ը�����ɿɿڡ�\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 2);
                set("food_supply", 40);
        }
}

