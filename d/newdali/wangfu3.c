// Code of ShenZhou
// Room: /d/dali/wangfu3.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡������Ǹ���԰��һ
����Ũ���Ļ����˱Ƕ�����
LONG);
	set("exits", ([
		"north" : __DIR__"wangfu4.c",
		"south" : __DIR__"wangfu2.c",
		"west" : __DIR__"wangfu6.c",
		"east" : __DIR__"wangfu5.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
