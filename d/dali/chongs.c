// Code of ShenZhou
// Room: /d/newdali/chongs.c

inherit ROOM;

void create()
{
	set("short", "千寻塔");
	set("long", @LONG
这是崇圣寺三塔的主塔，名叫千寻塔。塔体呈方形，密椽式，
共十六层，高约二十三丈。不少文人在塔上题诗赋词，塔顶四角
各有一只铜铸的金鹏鸟，传说可以镇压洱海中的龙妖水怪。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/dali/npc/sengren" : 2,
]));
	set("cost", 3);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wanrenzhong",
  "enter" : __DIR__"chongs1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
