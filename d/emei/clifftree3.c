// Code of ShenZhou
// d/emei/clifftree3.c ����������
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "��������");
	set("long", @LONG
���Ѿ��������������¡�������������Զ��������ʯ���г�����������
���±ڡ�
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"�������¶�̫Զ�ˣ������������ȥ�ˡ�\n",
	    "down"	:
"������������Ԩ��\n",
	    "cliff"	:
"�±��ƺ������õ�����һ��ƽ���±�����ͻ��һ�飬��֪�����Ƿ���ʲô֧��
��������ȥ��\n",
	    "left"	:
"�±��ƺ������õ�����һ��ƽ���±�����ͻ��һ�飬��֪�����Ƿ���ʲô֧��
��������ȥ��\n"
        ]));

	set("cost", 0);
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

	if ( arg && arg != "down" && arg != "up" && arg != "left")
		return notify_fail("ʲô��\n");

	if ( arg == "down" ){
		call_out("to_pool", 1, me);
                message_vision("$N��������ȥ����Ȼһ��ʧ�֣�ֱˤ����ȥ����\n", me);
	        return 1;
	}

	if ( arg == "up" ) {
		message_vision("$N˳��������������ȥ��\n", me);
		me->move(__DIR__"clifftree2");
		message_vision("$N˳����������������\n", me);
		me->add("jingli",-random(20));
		return 1;
	}

	if (arg == "left" ) {
		message_vision("$N�����±��������ȥ��\n", me);
		me->move(__DIR__"cliffpath1");
		message_vision("$N�����±ڴ��ұ����˹�����\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"
