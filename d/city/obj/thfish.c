// Code of ShenZhou
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "̫������" NOR, ({"taihu yinyu", "yinyu", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��������ϸ�ۣ������㡢��Ϻ���ơ�̫������������Ʒɫ���ƣ��������ۡ�\n"  );
                set("unit", "��");
                set("value", 420);
                set("food_remaining", 5);
                set("food_supply", 60);
        }
}
