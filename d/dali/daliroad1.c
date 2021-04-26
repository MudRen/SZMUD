// Code of ShenZhou
// daliroad1.c
// by Lyu

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。西边通向大理。
LONG
	);
        set("outdoors", "dali");

	set("exits", ([
		"west" : __DIR__"eastgate",
		"east" : __DIR__"daliroad2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

