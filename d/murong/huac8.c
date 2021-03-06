// Code of ShenZhou
// Room: /d/murong/huac8
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "花林深处");
	set("long", @LONG
    转过一座小山，只听得溪水湍湍，左首一排绿竹，
四下里甚是幽静。该地在山丘之阴，日光照射不到，是
种植山茶的好地方。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "southeast" : __FILE__,
        "west" : __FILE__,
        "north" : __DIR__"huac7",
        "east" : __DIR__"mantuo2",
        "southwest" : __FILE__,
        "south" : __FILE__,
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/kungfu/class/murong/yuyan" : 1,
		]));

	setup();
        replace_program(ROOM);
}

