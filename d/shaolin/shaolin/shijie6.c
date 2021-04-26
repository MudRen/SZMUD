// Code of ShenZhou
// Room: /d/shaolin/shijie6.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工
凿出一格格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。
瀑布在脚下奔腾而过，在不远的山脚下汇成一个深潭。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie5",
		"northup" : __DIR__"shijie7",
		"eastup" : __DIR__"shijie12",
	]));

	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



