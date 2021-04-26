// Code of ShenZhou
// Room: /d/dali/wangfuroad2.c

inherit ROOM;

void create()
{
	set("short", "�·");
	set("long", @LONG
ֻ�����ߴ����·�������²�̦�������м���һ��ʯ�������·��
LONG);
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"wangfu10",
		"north" : __DIR__"wangfu9",
		"west" : __DIR__"wangfuroad1",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
