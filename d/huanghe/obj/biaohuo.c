// Code of ShenZhou
// biaohuo.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"����"NOR, ({"hong biao", "biao"}));
        set("weight", 20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
"����һ�ݺ��ڣ���װ�طǳ���ϸ����֪װ��ʲô������\n");
                set("unit", "��");
                set("value", 30);
        }
        setup();
}
