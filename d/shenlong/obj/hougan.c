// Code of ShenZhou
// hougan.c  ���

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("���", ({ "hou gan", "gan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ϻ�ɫ�ĺ�Ρ�\n");
                set("value", 1000000000);
                set("medicine", 1);
        }
        setup();
}
