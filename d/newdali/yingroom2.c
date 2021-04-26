// Code of ShenZhou
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��̶С��");
	set("long", @LONG
ǽ���Ǹ�Ժ�ӣ���Ϊ���룬��һ����ʵ������һ��ȴ��ˮ��������ǰ�Ǹ���
�����������顣ֻ����ǰ����һ�ų��������������յ�͵ƣ��ų������֮�Ρ�
�������߰���ذ���һ������������Ƭ����Щ��Ƭ���ǳ�Լ�Ĵ磬��Լ���֣���
���Ǽ����õ����ӡ�
LONG);
	set("objects", ([
		__DIR__"npc/yinggu" : 1,
		]) );
	set("exits", ([
		"out" : __DIR__"maze2",
        ]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
