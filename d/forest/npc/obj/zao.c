// Code of ShenZhou
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��", ({"zao"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������ĺ��档\n");
                set("unit", "��");
                set("food_remaining", 1);
                set("food_supply",20 );
        }
}

