// Code of ShenZhou
// room: /d/baituo/barn4b.c
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
		"up" : __DIR__"barn4a",
	]));
	replace_program(ROOM);
	set("cost", 2);
	setup();
}
