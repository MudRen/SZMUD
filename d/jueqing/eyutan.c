// Filename:   /d/jueqing/eyutan.c ����̶
// Jiuer, Aug 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIC"����̶"NOR);
	set("long",@LONG
����һ���ִ������̶��̶�ںڵÿ��������̶����������Ư����
һЩ������̶ˮ������ֱ����ս������ɽ�º����и�ɽ���������
(swim)��ȥ�����ɡ�
LONG);
	set("objects" , ([
		"/d/jueqing/npc/crocodile": 1,
		]));
	set("resource/water", 1);	
	set("cost",3);

	setup();	
}

void init()
{ 
	add_action("do_swim","swim");
}

int do_swim(string arg)
{
        object me = this_player();
        int cost;


        if(me->is_busy())
			return notify_fail("�㻹��æ���ء�\n");

        //cost = (200-me->query_skill("swimming",1))/10;
        //if ( cost<3 )cost = 3;
        //me->add("jingli",-cost);
        //me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
        me->add("jingli", -200);
        me->start_busy(random(3));

	if( !arg || arg ==" ")
	return notify_fail("��ֻ���������Σ�\n");
        if (arg == "east")
			return notify_fail("���Ѿ���̶�����ˣ����������ߡ�\n");
	
		if(arg == "west")
		{
			message_vision( HIY"\n$N������̶��ƴ����ˮ����������������\n"NOR, me);
			me->move(__DIR__"shandong",5,me);
			message_vision( HIY"\n$N���˹�����\n"NOR, me);
			return 1;	
		}		
}

