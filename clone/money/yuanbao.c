// Code of ShenZhou

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIY"��Ԫ��"NOR, ({"jin yuanbao", "yuanbao_money", "yuanbao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "yuanbao");
                set("long", "һ�������Ľ�Ԫ����\n");
                set("unit", "Щ");
                set("base_value", 100000);
                set("base_unit", "��");
                set("base_weight", 3000);
        }
        set_amount(1);
}

