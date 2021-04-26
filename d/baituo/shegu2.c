// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�߹�ɽ��");
	set("long", @LONG
���ǰ���ɽ�߹��е�ɽ·����һ������ȳ�����С�������ŵ���
����������������С�
LONG
	);

	set("exits", ([ 
	    "southup" : __DIR__"shegu1",
	    "northwest" : __DIR__"shegu3",
	]));

	set("cost", 5);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}

int valid_leave(object me, string dir)
{
	object room;
	int i, w;

	room = load_object("/d/baituo/shegu1");

	if (dir == "southup") {
		if ( !me->query("baituo/shegu_permit") && room->query("defense") )
			return notify_fail("�����߳��߹ȣ����ǹȿں�����������һ�߽�������ȳ��˱ǣ��о�����Щ��ѣ��\n�������Ǽ�Ϊ�����Ķ�������ǿ��ͨ����\n");
	}
	return ::valid_leave(me,dir);
}
