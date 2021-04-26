// Filename:   /d/jueqinggu/shandong.c ɽ��
// Jiuer Aug 15, 2001
#include <ansi.h>
inherit ROOM;
int do_pa(string arg);
void create()
{
		  set("short","��ɽ��");
		  set("long",@LONG
����̶�ߵ�һ����ɽ�������ڼ�խ��ֻ��ϥ�ж�����������̶ˮ��
���������г�ʪ����ȳ����š�
LONG);
		
		  set("cost",1);
		  setup();	
}

void init()
{
	add_action("do_pa","pa");
	add_action("do_swim","swim");
}

int do_pa(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "west")
		return notify_fail("��ֻ����������\n");

	if ( arg == "west") {	
		message_vision("$N��ϥ��������ȥ��\n", me);	
		me->move(__DIR__"tongdao");
	//	me->delete_temp("marks/ok");
		message_vision("$N������һ���������ѿ�ֱ�����ߡ�\n", me);
		return 1;
	}
    return 0;
}

int do_swim(string arg)
{
        object me = this_player();
        int cost;

        if(me->is_busy())
                return notify_fail("�㻹��æ���ء�\n");

        cost = (200-me->query_skill("swimming",1))/10;
        if ( cost<3 )cost = 3;
        me->add("jingli",-cost);
     // me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
        me->start_busy(random(3));

        if (arg == "west")
        {
			return notify_fail("���Ѿ���̶�������ˡ�\n");
        }
		else if(arg =="east")
		{
			message_vision( HIY"\n$N������̶��ƴ����ˮ����������������\n"NOR, me);
			me->move("/d/jueqing/eyutan");
			message_vision( HIY"\n$N���˹�����\n"NOR, me);
			return 1;
		}
		return 2;
}

