// Code of ShenZhou
// room: /d/baituo/barn1b.c
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
		"south" : __DIR__"barn1a",
	]));
	replace_program(ROOM);
	set("cost", 2);
	setup();
}
