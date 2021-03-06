// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "下关城");
	set("long", @LONG
下关城，又名龙尾城，为阁罗凤所筑，唐代已极繁荣。城区萦抱
苍山南麓数里，洱水绕城南而过，端的风景如画。此去南边不远即是
大理城，东面有太和城，另有道路通向西北。此附近居民以乌夷、台
夷为主，也有少量摆夷。
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov90",
		"south" : __DIR__"esqiao",
		"northeast" : __DIR__"cangshan.c",
		]));

	set("objects", ([
		"/d/dali/npc/wyshang.c" : 1,
		"/d/dali/npc/tyshang.c" : 1,
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
