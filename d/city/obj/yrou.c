// Code of ShenZhou
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BRED+WHT "ˮ������" NOR, ({"shuijing yaorou", "yaorou", "rou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɫ�ʺ죬Ƥ�׹⻬��Ө��±��͸����״��ˮ����������������֣�\n�����壬ζ��������ˮ�����⡣\n"  );
                set("unit", "��");
                set("value", 250);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
}

