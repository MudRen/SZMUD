// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土路上，行人多是本地的摆夷族人。
也间或有些中原打扮的人事走动，此路东北面通向官道，向西有路通往大
理城的南门。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"tulu5.c",
		"west" : __DIR__"tulu7.c",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
