// Code of ShenZhou
// room: /d/baituo/barn5a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�����ң����յ��ӳ�������ѱ�����ߣ��������и�С�š�
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"kongdi1",
		"south" : __DIR__"barn5b",
	]));
	create_door("northwest", "ľ��", "southeast");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
