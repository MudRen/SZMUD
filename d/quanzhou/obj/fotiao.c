// Code of ShenZhou
// fotiao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����ǽ", ({"fo tiao qiang", "fo"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ǽ��Ȫ������¥�����ˡ�\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 100);
        }
}

