// Code of ShenZhou
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ձ�", ({"shaobing", "cake"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ĵ��ձ��������дл���������֥�顣\n");
                set("unit", "��");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

