// Code of ShenZhou
// room: /d/baituo/barn1a.c
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
		"north" : __DIR__"barn1b",
		"west" : __DIR__"road1",
	]));
	create_door("west", "ľ��", "east");

	replace_program(ROOM);
	set("cost", 1);
	setup();
}
