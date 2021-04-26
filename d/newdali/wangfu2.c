// Code of ShenZhou
// Room: /d/dali/wangfu2.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
����������ǰԺ��һ��Ӱ�ڽ�Ժ�ӷֳ����롣��������������������ͨ��ͨ
�����Ǵ������ү�ǵĸ��ڡ�
LONG);
	set("objects", ([
		__DIR__"npc/xiaosi" : 2,
		__DIR__"npc/cui" : 1,
		]));
	set("exits", ([
		"southwest" : __DIR__"sangong.c",
		"north" : __DIR__"wangfu3.c",
		"out" : __DIR__"wangfu1.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
