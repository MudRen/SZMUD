// Code of ShenZhou
// jiuzhuan-huanhundan.c ��ת���굤 (fake)

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");       
}

void create()
{
        set_name("��ת���굤", ({"jiuzhuan dan", "jiuzhuan", "dan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ž�������ľ�ת���굤�����������������������\n");
                set("value", 0);
        }
        set_color(HIY);
        set("qfy",1);

        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIG "$N����һ�ž�ת���굤�����ֻ���һ˿˿���뿪���壬�书��ʧ��\n" NOR, me);
                write(HIY"���˽ڿ���\n���˽ڿ���\n���˽ڿ���\n���˽ڿ���\n");
        return 1;
}

