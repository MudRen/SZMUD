// Code of ShenZhou
// jiuer 6/2002
// d/baituo/road1b.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ������ɳʯ��С��������ͨ��ɽׯ��ǰԺ���ϱ���һ��С����
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"road2",
		"north" : __DIR__"road1a",
		"east" : __DIR__"barn3a",
	]));

	create_door("east", "ľ��", "west");

	set("outdoors","baituo");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
