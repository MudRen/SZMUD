// Code of ShenZhou
// wdroad4.c
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
		"west" : __DIR__"wdroad5",
		"east" : __DIR__"wdroad3",
		"southup" : "/d/henshan/hsroad1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

