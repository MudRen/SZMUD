// Code of ShenZhou
// Room: /d/dali/dahejie.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。南面是
大理城的守军驻地，隐隐可以听到兵士们操练的号子声，向北是土司
府，是当今皇太妃刀氏一族的世袭衙门。
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([
		"north" : __DIR__"tusi1",
		"south" : __DIR__"bingying.c",
		"east" : __DIR__"crossing.c",
		]));

	setup();
}
