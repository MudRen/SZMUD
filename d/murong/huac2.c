// Code of ShenZhou
// Room: /d/murong/huac2
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "花林");
	set("long", @LONG
    只见小路东一条，西一条，不知哪一条才是来路。
眼前的山茶都是刚才没有看见过的。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __FILE__,
        "north" : __FILE__,
        "west" : __DIR__"huac3",
        "east" : __DIR__"mantuo2",
        "southwest" : __FILE__,
        "southeast" : __FILE__,
                      ]));
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}

