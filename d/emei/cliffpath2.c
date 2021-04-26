// Code of ShenZhou
// d/emei/cliffpath1.c �±�
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "�±�");
	set("long", @LONG
��վ���±��ϵ�ʯ��䣬Ҫ������ס�±�ͻ���ĵط��Ų�����ˤ��ȥ��ʯ
�������ɳʯ��ľ��ʲôҲû�С�
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
	    "down"	:
"������������Ԩ��\n",
		"cliff"	:
"�±����и���ʯ�죬������ȥ��\n",
        ]));

	set("cost", 10);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( arg == "down" ) {
                message_vision("$N����������ȥ��\n", me);
		call_out("to_pool", 1, me);
                return 1;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();
	int k;

	k = (int)me->query_dex() + (int)me->query_kar();

	if ( arg && arg != "down" && arg != "up")
		return notify_fail("�����ﲻ�ܳ��Ǹ���������\n");

	if ( arg == "down" ){
		if ( random(k) < 20 ) {
                	message_vision("$N��������ȥ����Ȼһ��ʧ�֣�ֱˤ����ȥ����\n", me);
			call_out("to_pool", 1, me);
	        	return 1;
		}
		else {
			message_vision("$N�����±����±���ȥ��\n", me);
			me->move(__DIR__"valley");
			message_vision("$N���±ں�����˹�����\n", me);
			me->add("jingli",-random(20));
			return 1;
		}
	return 0;
	}

	if (arg == "up" ) {
		if ( random(k) < 20 ) {
                	message_vision("$N�����±�������ȥ����Ȼһ��ʧ�֣�ֱˤ����ȥ����\n", me);
			call_out("to_pool", 1, me);
	        	return 1;
		}
		else {
			message_vision("$N�����±�������ȥ��\n", me);
			me->move(__DIR__"cliffpath1");
			message_vision("$N�����±ڴ���������������\n", me);
			me->add("jingli", -random(10));
			return 1;
		}
	return 0;
	}

	return 0;
}

#include "/d/emei/cliff.h"
