//Cracked by shenzhou
// road4.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�
LONG
	);
	set("outdoors", "sanbuguan");

	set("exits", ([
		"west" : "/d/sanbuguan/road5",
		"east" : "/d/sanbuguan/road3",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

