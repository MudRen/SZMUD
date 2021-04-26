// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土路上，行人多是本地的摆夷族人。
也间或有些中原打扮的人事走动，此路东北面通向官道，向西南有路通
往大理城的南门。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"tulu4.c",
		"southwest" : __DIR__"tulu6.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
