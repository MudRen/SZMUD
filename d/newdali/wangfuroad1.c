// Code of ShenZhou
// Room: /d/dali/wangfuroad1.c

inherit ROOM;

void create()
{
	set("short", "�·");
	set("long", @LONG
ֻ�����ߴ����·�������²�̦�������м���һ��ʯ�������·��
LONG);
	set("exits", ([
		"southeast" : __DIR__"wangfu4.c",
		"east" : __DIR__"wangfuroad2.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
