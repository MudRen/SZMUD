// Code of ShenZhou
// Room: /d/newdali/fatang.c

inherit ROOM;

void create()
{
	set("short", "法堂");
	set("long", @LONG
定安府的法堂内气氛肃穆，堂的上首摆的是一排五个长案，案后
坐的是五个不同族裔的官员。长案下首有两个通译，有赐座。此外，
法堂两边还站了四五衙役。
LONG
	);
	set("exits", ([
		"south" : __DIR__"dinganfu",
		]));


	set("objects", ([
		__DIR__"npc/duanjin" : 1,
		"kungfu/class/dali/wujiang1" : 1,
		__DIR__"npc/bypanguan" : 1,
       ]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
