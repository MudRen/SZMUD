// Code of ShenZhou
// room: /d/baituo/barn2b.c
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
		"west" : __DIR__"barn3a",
	]));
	replace_program(ROOM);
	set("cost", 2);
	setup();
}
