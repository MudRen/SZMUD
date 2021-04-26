// conglin.c (kunlun)

#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "ѩ�ش���");
                  set("long",@long
������һ��ѩ��Ĵ���֮�ڡ�ֻ��һ���޼ʵ�ѩ���������Լ�������һ����ӡ��
ǰ����һ������(cliff),����ɽ�����߰��������������ͷ��������������צ���ƽУ���
����Ҫʳ֮������������һ������׵�����Ͽ��.
long);
                 set("exits",([
"southdown" : __DIR__"shanpo",
]));


set("cost", 5);
set("outdoors", "kunlun");
setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("��Ҫ���Ķ�����\n");

        if (me->query_busy())
                return notify_fail("����æ���ء�\n");

         if( arg=="cliff")
        {
        message_vision("$N�������ϵ�����,�۾�һ��������������ȥ��\n", me);
        me->start_busy(5);

        if (random(me->query_skill("dodge")) < 50){
        remove_call_out("drop_down");
        call_out("drop_down", 5, me);
        return 1;
        }
        
        message("vision", me->name()+"һ�������ʧ��ɽ���������ˡ�\n", environment(me), ({me}) );
        remove_call_out("climb_up");
        call_out("climb_up", 5, me);
        return 1;
        }
}
void drop_down(object me)
{
        tell_object(me, "ͻȻ��ƫ���˷���ֱ����׹�䡣\n");
        message("vision", me->name() + "ͻȻ��һ̤�գ���ɽ���ϵ���С����\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 500, "���ͱ��ϵ�������ˤ����");
        me->receive_wound("qi",  500, "���ͱ���������ˤ����");
}
void climb_up(object me)
{
        tell_object(me, "������һ��������������ȥ����׼���������������ϡ�\n");
        me->add("jingli", -100);
        me->move(__DIR__"songshu");
        message("vision", me->name() + "ͻȻ���������������\n",
                             environment(me), ({me}) );
}

