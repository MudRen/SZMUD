// Code of ShenZhou
// Room: /d/murong/qing1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "琴韵小路");
	set("long", @LONG
这是琴韵小屋前的一块场地，前面是疏疏落落四五座房舍，
建造在一个不知是小岛还是半岛之上。房舍小巧玲珑，颇
为雅致。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "north" : __DIR__"qing2",
        "east" : __DIR__"road1",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
