// Code of ShenZhou
// shanlu4.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "ɽ·");
	set("long", @LONG
�����·�趸��һ������ʯ��֮����������������ɭɭ��������ˡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu3",
		"west" : __DIR__"gucheng1",
	]));
	set("outdoors","xingxiu");
	set("cost", 6);
	setup();
	replace_program(ROOM);
}

