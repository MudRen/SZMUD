// Code of ShenZhou
// Room: /d/newdali/shegu.c

inherit ROOM;

void create()
{
	set("short", "蛇骨塔");
	set("long", @LONG
蛇骨塔位于大理城内，建在点苍山斜阳峰东坡。相传洱海有妖蛇
名“薄劫”，其尾塞海口，洪水泛滥，有勇士段赤城只身入洱海与妖
蛇同归于尽。后人建塔以震水势，用蛇骨灰塔，水势自息。这是一座
密椽式方形砖塔。
LONG
	);

	set("objects", ([
		"/d/village/npc/kid" : 2,
		]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"east" : __DIR__"taihejie4.c",
		"west" : __DIR__"qingchi",
		]));
	set("no_clean_up", 0);

	setup();
}
