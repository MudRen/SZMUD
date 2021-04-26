//ROOM: /d/shaolin/shanlu2.c
// jiuer 08/2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路崎岖盘垣布满石头和蔓草。行走大为不便。你觉得两臂酸麻，
两腿发软，快要支撑不住了。这里常会有些少林寺的和尚下山担水。
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"xiaojing1",
		"southdown" : __DIR__"shanlu1",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}