// Code of ShenZhou
// Room: /d/dali/jiulou.c

inherit ROOM;

void create()
{
	set("short", "太和居");
	set("long", @LONG
这是大理城内最大的酒楼，楼下卖些大理的小吃，过往行人
常常买来作路菜。楼上是雅座。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiulou2.c",
  "west" : __DIR__"taihejie2.c",
]));

        set("objects", ([
"/d/dali/npc/xiaoer2" : 1,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

