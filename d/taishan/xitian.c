// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ʯ�������������ն�����Ƶģ�����᷶���������ڡ�
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

