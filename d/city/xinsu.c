// Code of ShenZhou
// Room: /city/xinsu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
xin su
��Ҫ�����˵������
LONG
	);

	set("exits", ([
		"east" : __DIR__"road4",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

