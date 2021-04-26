// Code of ShenZhou
// Room: /d/newdali/taihejie1.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
这条街由南门直通皇宫大门，是大理城内的主要街道。通街全用天然的
大块青石铺成。可容八马并驰，街上行人络绎不绝。洋溢着一派繁华的皇城
景象。
LONG	);

	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southgate.c",
  "north" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}









