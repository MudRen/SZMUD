// Code of ShenZhou
// room: /d/baituo/barn3a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�����ң����յ��ӳ�������ѱ�����ߣ��Ա��и�С�š�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"road1b",
		"east" : __DIR__"barn3b",
	]));

	create_door("west", "ľ��", "east");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
