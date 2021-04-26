// Code of ShenZhou
// d/emei/cliffpath1.c �±�
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "�±�");
	set("long", @LONG
�±���߲���ô��ͺͺ�ģ����������֮����ʯ��䳤��С��С�ݡ�
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
	    "down"	:
"������������Ԩ��\n",
		"cliff"	:
"�±ڶ����и���ʯ�죬������ȥ��\n",
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

	if ( arg && arg != "down" && arg != "right")
		return notify_fail("�����ﲻ�ܳ��Ǹ���������\n");

	if ( arg == "down" ){
		k = (int)me->query_dex() + (int)me->query_kar();
		if ( random(k) < 20 ) {
                	message_vision("$N��������ȥ����Ȼһ��ʧ�֣�ֱˤ����ȥ����\n", me);
			call_out("to_pool", 1, me);
	        	return 1;
		}
		else {
			message_vision("$N�����±����±���ȥ��\n", me);
			me->move(__DIR__"cliffpath2");
	                message_vision("$N�������´���������\n", me);
			me->add("jingli",-random(20));
			return 1;
		}
	return 0;
	}

	if (arg == "right" ) {
		message_vision("$N�����±����ұ���ȥ��\n", me);
		me->move(__DIR__"clifftree3");
		message_vision("$N�����±ڴ������������\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"

