// Code of ShenZhou
// Room: /d/dali/tulu4.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这里是大理境内，你走在一条黄土大路上，行人多是本地的摆
夷族人。也间或有些中原打扮的人事走动，此路北面通向官道，向
西北有路通往大理城的南门，东行可达广东佛山。
LONG
	);
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");

	set("exits", ([
		"northwest" : __DIR__"shqiao",
		"southeast" : "/d/foshan/dlroad7.c",
		]));

	setup();
}
