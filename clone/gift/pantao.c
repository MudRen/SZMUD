// pantao.c ���

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "���" NOR, ({ "tao", "pan tao", "pantao" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "������԰�����ң���˵���˿��Է��ϻ�ͯ��\n");
                set("value", 10000);
                set("unit", "��");
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$N���̻��ʵؽ�" + this_object()->name() +
                       "������ȥ��\n", me);
        if (random(10) >= 1)
        {
                tell_object(me, "����ú���ûʲô�仯��\n");
        } else
        {
                tell_object(me, HIG "��Ȼ�㷢���Լ��ļ�����ʼ�ɱ䣬������û���������\n");
               if(me->query("age")>14) me->add("mud_age", -99999);
        }
	me->add("story/pantao",1)
        remove_action("do_eat","eat");
        destruct(this_object());
        return 1;
}