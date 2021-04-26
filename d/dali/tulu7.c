// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土路上，行人多是本地的摆夷族人。
也间或有些中原打扮的人事走动，此路往东通往官道，向西通往大理城
的南门。
LONG );

	set("exits", ([
		"east" : __DIR__"tulu6.c",
		"west" : __DIR__"tulu8.c",
	]));

	set("objects", ([
		__DIR__"npc/wujian": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
