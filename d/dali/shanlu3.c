// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两
旁间或可见一些夷族的村镇。山路向南蜿蜒着。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanlu2.c",
		"southwest" : __DIR__"shanlu4.c",
		]));

	set("objects", ([
		__DIR__"npc/snbz": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
