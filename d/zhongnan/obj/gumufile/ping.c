// ping.c �佬ƿ

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�佬ƿ", ({ "fengjiang ping", "ping" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value", 0);
        set("material", "��");
        set("long", "����һ�����Ϲ������ɵ�Сƿ����δ�ο�ƿ�����Ϳ����ŵ�\n"
                    "һ��Ũ������ζ�������������䡣\n") ;
	set("max_liquid", 20);
        }
        setup();
}


