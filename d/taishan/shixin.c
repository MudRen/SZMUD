// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
// modified by qfy July 13, 1996.

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�������������ķ嶥���������ʯ������һ�𣬾�˵������
�Ĵ���⣬��������ʯʱʯ��㲻�ᶯҡ����֮��ҡ����ֹ��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));

	set("outdoors", "taishan");
	set("cost", 2);
	setup();
}

void init()
{
	object me = this_player();
	int check, wait_time = 0;

        me->delete_temp("marks/Ĺ");
        me->delete_temp("marks/��");
	me->delete_temp("marks/ǽ");
	me->delete_temp("marks/С");

	if ( me->query_temp("marks/��") && interactive(me) && !me->is_fighting() ) {
           call_out("open_up", 1200, me);
	}
}

int open_up(object me)
{
        message_vision("$N�ĳ�����ص������ã�ͻȻ���һ���𶯣���������ʯ��\n", me);
	message_vision("�ѿ�����¶��һ��խխ���ܾ���\n", me);
	me->set_temp("marks/��", 1);
	set("exits/enter", __DIR__"mijing");
	call_out("close_up", 5, me);
	return 1;
}

int close_up(object me)
{
	message_vision("����һ��ɽҡ�ض�����������ʯ�𽥺�£������\n", me);
	delete("exits/enter");
	me->delete_temp("marks/��");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("marks/��") && dir == "enter" )
	   return notify_fail("�����ⲻ�ϣ����ܽ����ܾ���\n");
	else if ( me->query_temp("marks/��") && dir == "southdown" ) {
	   remove_call_out("open_up");
	}

	return ::valid_leave(me, dir);
}
