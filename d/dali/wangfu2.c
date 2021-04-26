// Code of ShenZhou
// Room: /d/newdali/wangfu2.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是王府的前院，一道影壁将院子分成两半。北面是王府正区，
南面通向通向侯府，是大理国侯爷们的府第。
LONG
	);
	set("objects", ([
		__DIR__"npc/xiaosi" : 2,
		__DIR__"npc/cui" : 1,
		]));

	set("cost", 1);
	set("exits", ([
		"west" : __DIR__"sangong.c",
//		"south" : __DIR__"diziarea",
		"north" : __DIR__"wangfu3.c",
		"out" : __DIR__"wangfu1.c",
		]));
	set("no_clean_up", 0);
	set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
