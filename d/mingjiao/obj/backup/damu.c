// Code of ShenZhou
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"��ľ��"NOR,({ "bole" }));
        set_weight(70000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ľ�ɣ�ľ��װ��������\n");
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("self_destruct", 1);
        }
        
        setup();
}

int value()
{
        return 1;
}
