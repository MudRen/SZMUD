// Code of ShenZhou
// changle/clguibin.c

inherit ROOM;

void create()
{
        set("short", "贵宾室");
        set("long", @LONG
这是长乐帮的贵宾休息室，十分的华丽。
LONG );
        set("exits", ([
		"east" : __DIR__"clhoulang3",
        ]));

	
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_steal", 1);

        set("cost", 0);

        setup();

        // replace_program(ROOM);
}



