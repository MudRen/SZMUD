// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路
两旁间或可见一些夷族的村镇。山路向南蜿蜒着。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"shanlu3.c",
		"southeast" : __DIR__"shanlu6.c",
		]));

	set("objects", ([
		__DIR__"npc/wujian": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
