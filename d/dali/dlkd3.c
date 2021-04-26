// Code of ShenZhou
// dali kedian

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这是一间很大的客房，窗外是一片青竹林，靠窗子放了十几张竹
床，不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是
空的，你蹑手蹑脚地走了过去。
LONG
	);

	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);

	set("exits", ([
		"out" : __DIR__"dlkd2",
	]));

	set("cost", 1);
	setup();
}
