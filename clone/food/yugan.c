// Code of ShenZhou
//�����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�����", ({"yu gan", "yu", "fish"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ƺõ������\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 6);
                set("food_supply", 50);
        }
}

