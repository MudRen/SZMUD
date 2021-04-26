// Filename:   /d/jueqinggu/jueqingfeng.c  �����
// by Jiuer  08/15/2001

#include <ansi.h>
inherit ROOM;

void create()
{
	int i;
		set("short",WHT"�����"NOR);

		set("long",
"���Ｋ�����У�̧ͷ��ɽ��������嶥��������֮�У���֪��ͷ��
���������Ĵ�ݲ��������������ƣ�������ң������Ҳ�����ڷ�
��ͣ�㡣���Ǿ���֮�صġ�"+WHT"�����"NOR+"����\n"
);
		set("outdoors","jueqing");

		i = random(2);
		    switch(i) {
		case 0:
			set("objects", ([
				__DIR__"obj/longhua" : 1,
				]));
		break;
		case 1:
			set("objects", ([
				"clone/herb/duanchang" : 1,
				]));
			break;
			}
		set("cost",2);
		setup();	
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object me = this_player();
	if( !arg )
		return notify_fail("ʲô?\n" );

	if(me->query_busy())
		return notify_fail("��������\n");
	
	if( arg != "down")
		return notify_fail("��ֻ��������! \n" );
	
	
	if( arg =="down")
	{
		
		message_vision("$NС����������±���������ȥ��\n", me);
	    me->start_busy(5);

		me->add("jingli",-50);
		
		me->move(__DIR__"duanchang");
		message("vision", me->name()+"�����شӷ嶥����������\n", environment(me), me);

		return 1;
	}
}

void drop_down(object me)
{
        tell_object(me, "$NͻȻ����һ�������ͱ��ϵ���������ˤ�˸��������ס�\n");
        message("vision", me->name() + "ͻȻ����һ�������ͱ��ϵ���������ˤ�˸��������ס�\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 100, "���ͱ��ϵ�������ˤ���ˡ�");
        me->receive_wound("qi",  100, "���ͱ��ϵ�������ˤ���ˡ�");
}

/*void climb_down(object me)
{
        tell_object(me, "$N���������һ�������ֽ���ס�·졣\n\n");
        me->add("jingli", -50);
        me->move(__DIR__"duanchang");
        message("vision", me->name() + "���������ش���������������\n",
                             environment(me), ({me}) );
}
*/