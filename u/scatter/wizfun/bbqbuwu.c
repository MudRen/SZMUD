 // Code of ShenZhou
// kaoya.c ��Ѽ

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
        switch(random(8))
        {
        case 0:
        set_name(HIY"�տ������ƨ��"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 1:
        set_name(MAG"�տ������ƨ��"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 2:
                set_name(HIC"�տ���������"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 3:
                set_name(HIC"�տ�������ҽ�"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 4:
                set_name(HIW"�տ����������"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 5:
                set_name(HIG"�տ����������"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 6:
                set_name(HIM"�տ�������ز�"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 7:
                set_name(HIB"�տ������ͷ��"NOR, ({"bbq buwu", "buwu"}));
                break;
        case 8:
                set_name(HIB"�տ������ͷ��"NOR, ({"bbq buwu", "buwu"}));
                break;
        }


        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�տ����䡣\n");
                set("unit", "ֻ");
                set("value", 120);
                set("food_remaining", 3);
                set("food_supply", 80);
        }

        setup();
}
