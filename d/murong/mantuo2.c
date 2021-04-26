// Code of ShenZhou
// Room: /d/murong/mantuo2
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "花林");
	set("long", @LONG
    着里所植的山茶均平平无奇，唯一的好处只是得个“多”
字。往前看，山茶品种渐多，偶尔也有一两本还算不错，却
也栽种不得其法。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo3",
        "north" : __DIR__"mantuo1",
        "west" : __DIR__"huac1",
                      ]));
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}

