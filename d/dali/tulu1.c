// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土路上，行人多是本地的摆夷族人。
也间或有些中原打扮的人事走动，此路北面通向官道，向南有路通往大
理城的南门。
LONG
	);

	set("exits", ([
		"north" : __DIR__"guandao5",
		"south" : __DIR__"tulu2.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
