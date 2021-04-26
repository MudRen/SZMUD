// Code of ShenZhou
// 华山玉女峰山路
// qfy 26/6/1996

inherit ROOM;

void create()
{
	set("short", "玉女峰山路");
	set("long", @LONG
这是一条通向玉女峰绝顶上危崖的山路。一路上来，草木越来越少，
与华山草木清华，景色极幽的特色成对比。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"yunu",
		"northup":__DIR__"shanlu2",
	]));

	set("objects", ([
		CLASS_D("huashan") + "/genming" : 1, 
	]));

	set("outdoors", "huashan");

	set("cost", 3);
	setup();
}


 
