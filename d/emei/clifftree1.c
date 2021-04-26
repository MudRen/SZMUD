// Code of ShenZhou
// d/emei/clifftree1.c ���������޺���
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "�޺���");
	set("long", @LONG
����һֻ����֦����һ���޺��������������޺���������ɼ����Ҷ��Բ
��ϸ����̧ͷ��ȥ�������������¶���Զ������ȴ��������Ԩ��
LONG
	);

        set("outdoors", "emei" );

        set("item_desc",([
            "up"        :
"����������¶���Զ����֪��û�����ܴ������������ȥ�أ�\n",
	    "down"	:
"������������Ԩ������Ѳ���������������\n"
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
                if (me->query("kar") > 15+random(15) 
		&& me->query_str() > 28 && me->query("dex") < 17
		&& me->query("con") > 18 && me->query("int") < 25) {
//require a low int here. ɵ����ɵ����
			call_out("to_branch2", 1, me);
	                return 1;
                }
                else {
			call_out("to_pool", 1, me);
       		        return 1;
		}
		return 0;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();
	int k;

	if ( arg && arg != "down" && arg != "up")
		return notify_fail("ʲô��\n");

	if ( arg == "down" ){
		message_vision("$N����������Ȼһ��ʧ�֣�ֱˤ����ȥ��\n", me);
		call_out("to_pool", 1, me);
	        return 1;
	}

	k = (int)me->query_str()+(int)me->query_dex();

	if ( arg == "up" ) {
		if (( random(k) > 40) && (me->query("jingli") > 60)) {
			message_vision("$NС�ĵ�������ȥ��\n", me);
			me->move(__DIR__"duguang2");
			message_vision("$NС������ش�������������\n", me);
			me->add("jingli",-random(60));
			return 1;
		}
		else {
			message_vision("$N��������������û����ȥ���ֵ������ˡ�\n", me);
			me->add("jingli",-random(10));
			return 1;
		}
	}
	return 0;
}

#include "/d/emei/cliff.h"
