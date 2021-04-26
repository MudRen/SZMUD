// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "万劫谷谷中");
	set("long", @LONG
你来到了万劫谷内，对面不远处是几间瓦房，左首边另有一间小
瓦房。两边的山壁很陡峭，看来是没法上下的。谷中一条小路绕过正
面的房舍通往谷后，不知去向什么地方。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wjg1.c",
		"north" : __DIR__"wjg3.c",
		"west"  : __DIR__"wjg4.c",
	]));

	set("objects", ([
		__DIR__"npc/jinxi": 1,
		__DIR__"npc/laifu": 1,
	]));

	set("cost", 1);
	set("outdoors", "dali");
	setup();
}
