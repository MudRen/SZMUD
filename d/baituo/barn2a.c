// Code of ShenZhou
// room: /d/baituo/barn2
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
		"west" : __DIR__"barn2b",
            "east" : __DIR__"barn",
	]));
	
	create_door("east", "ľ��", "west");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
