//Modified by Zyu on k1-8-6

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
һ�����ɻԻ͵���ݡ���������Ա߰�������ͷ�ߴ����ͣ���������
��ʯʨ�ӡ����Ϲ���һ��ڵ״��Ҷ�ĸ�ˢ��Ĵ��֣���������ݡ���
�����⡣��߲���һ�����ɶ�ߵ���ˣ����š��䡱�ֵĺ������Ʈ�
����ǽ������������ϣ�������������ݣ��ö���е��ӵܶ��ڴ�ѧЩȭ
�ű������򡣹�������º����ÿͣ������ϳ�֮�硣��Ƹ��ͷ����һ��һ
�ľ��湦��ĺ��֡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"gardeno",
		"east" : "/d/quanzhou/minzai2",
	]));

	set("objects", ([
//		__DIR__"npc/dadizi" : 1,
		__DIR__"npc/xuetu1" : 3,
	]));

	set("cost", 1);
        set("outdoors", "wuguan" );

	setup();
}

void init()
{
	object me = this_player();

	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_kill", "steal");
	add_action("do_sleep", "sleep");
}

int do_kill(string arg)
{
	object me = this_player();

	tell_object(me,"���ڴ������ǰҲ�������ע�⣿\n");
	return 1;
}

int do_sleep(string arg)
{
	object me = this_player();

	tell_object(me,"����ݿɲ������˯����Ŷ��\n");
	return 1;
}

