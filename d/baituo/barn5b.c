// Code of ShenZhou
// room: /d/baituo/barn5b.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�����ң����յ��ӳ�������ѱ�����ߡ�
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"barn5a",
	]));
	replace_program(ROOM);
	set("cost", 2);
	setup();
}
