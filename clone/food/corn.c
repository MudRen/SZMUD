// Code of ShenZhou
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BBLK+YEL "������" NOR, ({"corn", "kao yumi", "yumi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������������˵����ף������ڵĲ���ɢ������ζ��\n"  );
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

