// Code of ShenZhou
// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���Ĳ�", ({"kongxin cai", "cai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������͵Ŀ��Ĳˡ�\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply",20 );
        }
}

