// Code of ShenZhou
// Jay 10/8/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�߸�", ({"shegeng", "geng"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����������߸���Ӫ���ü��ˡ�\n");
                set("unit", "��");
                set("value", 75);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}

