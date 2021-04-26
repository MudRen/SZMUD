// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土路上，行人多是本地的摆夷族人。
也间或有些中原打扮的人事走动，此路西边就是大理城的南门了，向东
有路通往去中原的官道。
LONG
	);

	set("exits", ([
		"east" : __DIR__"tulu7.c",
		"west" : __DIR__"southgate.c",
		"north" : __DIR__"droad4.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
