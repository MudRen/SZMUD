// Code of ShenZhou
// paomo.c �������� 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��������", ({"yangrou paomo", "yangrou", "paomo"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����������������ɡ�\n");
                set("unit", "��");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}
