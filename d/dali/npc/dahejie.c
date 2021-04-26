// Code of ShenZhou
// Room: /d/newdali/dahejie.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。南面是大理城
的守军驻地，隐隐可以听到兵士们操练的号子声，向北是土司府，是当今皇
太妃刀氏一族的世袭衙门。
LONG	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tusi1",
  "south" : __DIR__"bingying.c",
  "east" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}








