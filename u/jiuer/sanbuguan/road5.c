//Cracked by shenzhou
// road5.c

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
		"west" : __DIR__"road6",
		"east" : __DIR__"road4",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

