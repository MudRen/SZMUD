// Code of ShenZhou
// jiuer 6/2002
// /d/baituo/road1a
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ������ɳʯ��С��������ͨ��ɽׯ��ǰԺ���ϱ���һ��С����
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"road1b",
		"north" : __DIR__"btyard",
	]));
	set("outdoors","baituo");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
