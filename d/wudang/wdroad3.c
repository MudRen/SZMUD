// Code of ShenZhou
// wdroad3.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad4",
		"east" : __DIR__"wdroad2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

