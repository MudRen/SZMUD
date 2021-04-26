// Code of ShenZhou
// jiulao3.c ���϶�
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>
string *dir=({"up","left","right"});

int     do_next(string arg);
int     do_cry();
void create()
{

                                        
        set("short", HIW"��ɽ����"NOR);
        set("long", @LONG
����һ���˼�������ɽ�����������ﻬ��ɽ���վ�������һ��̤�գ��Ʊ�
������������е��÷������,�ഫ��ɽ�۽����ڴ˴���
LONG
        );

        set("objects", ([
                "/u/slow/questwg/hong2" : 1,
        ]));

        set("outdoors", "huashan");
        set("cost", 5);
       setup();
}
void init()
{
        add_action("do_next","climb");
        add_action("do_cry","cry");
}
int do_next(string arg)
{
        object me = this_player();
        int cost,dodge;

        dodge = me->query_skill("dodge",1)/20+1;
        cost = 4000/dodge+1;
        cost = random(cost) + 100;
        
        if(me->is_busy())
                return notify_fail("�㻹��æ���ء�\n");

        me->start_busy(2+random(2));
        
        if (!arg)
        {
                tell_object(me,"�������ĸ�������?\n"NOR);

                return 1;

        }
        if (me->query("jingli")<500)
        {
                tell_object(me,HIY"�������͸֧�����˹�ȥ��\n"NOR);
                me->add("jingli",-500);
                return 1;
        }
        
        if (arg == "down")
        {
                message_vision("$NС�������������ȥ��\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->add("jingli",-cost);
        
        }
        else
        {
                tell_object(me,"�������������\n");
                
        }
        
        
        return 1;
}

int do_cry()
{

        command("cry");
        

}
