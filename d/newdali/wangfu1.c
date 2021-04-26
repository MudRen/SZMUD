// Code of ShenZhou
// Room: /d/dali/wangfu1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"��������"NOR"��");
	set("long","����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ���һ����ң�
����"HIY"��ƽ��������"NOR"�ĸ����֡��ſ�վ���������������Ž��£���ִ�ֵ���������
��������������������վ�������м䣬Ŀ�����ش����Ŵ����ﾭ�������ˡ�\n"
);
	set("objects", ([
		__DIR__"npc/weishi1" : 1,
		__DIR__"npc/weishi2" : 2,
		"/kungfu/class/dali/zhuwanli" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"dalicheng1.c",
		"enter" : __DIR__"wangfu2.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	set("valid_startroom",1);
	setup();
	"/clone/board/dali_b"->foo();
}
void init()
{
	object me;
	if (interactive(me = this_player())
		&& me->query("family/family_name")=="����μ�"
		&& !me->query("dali/employee"))
	{
		me->set("dali/employee",1);
		me->set("dali/trust",100);
	}
}
int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("family/family_name")!="����μ�"
		&& !me->query("dali/employee")
		&& dir == "enter"
		&& living(ob=present("zhu wanli", environment(me))))
	return notify_fail("������ȵ��������˵ȣ��������ڡ�\n");
	return ::valid_leave(me, dir);
}
