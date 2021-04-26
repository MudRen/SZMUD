// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "古道");
	set("long", @LONG
一条石板古道，两边树木苍翠，山势平缓，南面是一望无际的西
双版纳大森林。大道北面有一片宏伟建筑，一堵里许长的红墙隔开，
越过墙头可见一座高楼耸立，正是大理名胜五华楼。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu6.c",
		"east" : __DIR__"shanlu8.c",
		"enter" : __DIR__"wuhua1.c",
		]));

	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "dali");
	setup();
}
