// Code of ShenZhou
// d/emei/clifftree2.c ��������������
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һֻ����֦����һ�����������������������øߴ�Ծ��������Զ��
������ʯ���г��������������±ڡ��ϱ߾����������ˡ�
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"�������¶�̫Զ�ˣ��о�����Ų������������ˣ���Ҳ��֪�ܷ�������ȥ��\n",
	    "down"	:
"������������Ԩ������Ѳ���������������\n",
	    "tree"	:
"����������ʯ���г��������������±ڡ�\n",
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

	if ( arg && arg != "down" && arg != "up" && arg != "tree")
		return notify_fail("�����ﲻ�ܳ��Ǹ���������\n");

	if ( arg == "down" ){
                message_vision("$N��������ȥ����Ȼһ��ʧ�֣�ֱˤ����ȥ����\n", me);
		call_out("to_pool", 1, me);
	        return 1;
	}

	if ( arg == "up" ) {
		message_vision("$N��������������û����ȥ���ֵ������ˡ�\n", me);
		me->add("jingli",-random(20));
		return 1;
	}

	if (arg == "tree" ) {
		message_vision("$N˳��������������ȥ��\n", me);
		me->move(__DIR__"clifftree3");
		message_vision("$N˳����������������\n", me);
		me->add("jingli", -random(10));
		return 1;
	}

	return 0;
}

#include "/d/emei/cliff.h"
