// Code of ShenZhou
//rama@sz

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��֪������", ({"noname book"}));
        set_weight(10);
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ƾɾɵ��飬��֪������ʲô����д�ɵġ�\n");
                set("unit", "��");
                set("material", "paper");
                set("value", 2000);
                set("no_sell", 1);
        }
}


