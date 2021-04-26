// Code of ShenZhou
// Room: /d/dali/dlkd1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�͵�"NOR);
	set("long", @LONG
����ϲ�ݳ���Ψһ��һ�ҿ�ջ��ר�ŽӴ��������̣�����ǳ���¡����С��
��������æ������ת���˼���ƫԶ��ȴ�����ƿ��׿��ˣ�ס��һ��ֻҪ�������ӡ�
LONG);
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov64",
		"up" : __DIR__"dlkd2",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("valid_startroom", 1);
	setup();
}
int valid_leave(object me, string dir)
{
	string id;
	int i;

	if(me == present("xiao er"))
		return ::valid_leave(me, dir);

	if(objectp(present("xiao er", environment(me))))
	{
		if ( !me->query_temp("rent_paid") && dir == "up" )
			return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
		if ( me->query_temp("rent_paid") && dir != "up" )
			return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ����˻���ΪС���ź����أ�\n");
	}
	return ::valid_leave(me, dir);
}
