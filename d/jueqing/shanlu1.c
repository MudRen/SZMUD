// Jiuer Aug 15, 2001
// /d/jueqing/shanlu1.c

inherit ROOM;

void create()
{
	set("short","山路");

	set("long",@LONG
这里的山路非常陡峭，若非有绝顶的轻功，只怕一失足就要摔下山
去。走到这里你不禁稍稍有些累了。前面一堵峭壁迎面堵住了上山的去
路。
LONG);
	set("exits",([
		"southdown" : __DIR__"shanlu2",
		]));
	set("cost", 1);
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}
