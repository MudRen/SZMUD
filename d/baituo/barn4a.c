// Code of ShenZhou
// room: /d/baituo/barn4a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǰ���ɽׯ�����ң����յ��ӳ�������ѱ�����ߣ��������и�С��
ͨ������Ŀյء�
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"barn4b",
		"northeast" : __DIR__"kongdi1",
	]));

	create_door("northeast", "����", "southwest");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
