// Code of ShenZhou
// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "ǧ���");
	set("long", @LONG
����ǧ���������������ȣ��߱����硣���﹩�����
����𣬼��а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�
ʮ��٤�����Լ����������������ĵȡ�ֱ�������ۻ����ҡ�����
�е�Сľ�š�
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"guangchang5",
		"north" : __DIR__"bamboo1",		
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-guan" : 1,
	]));

	create_door("north","ľ��","south",DOOR_CLOSED);

	set("cost", 1);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "������" 
	&& dir == "north" 
	&& objectp(present("qingguan biqiu", environment(me))))
		return notify_fail("��ۺȵ����㲻�����ֵ��ӣ����ý����ɽ���֣�\n");

	return ::valid_leave(me, dir);
}