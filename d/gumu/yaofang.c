// July 31,2000
// Code by April
// /gumu/yaofang.c

inherit ROOM;

void create()
{
	set("short","药房");

	set("long",@LONG
这是一间药房。屋子一角有个药炉，闻名天下的古墓圣药就在这里炼制。
LONG);

	set("exits",([ 
		"south" : __DIR__"mudao16",
		]));

	set("objects", ([
             "/kungfu/class/gumu/obj/yaolu" : 1,
             "/kungfu/class/gumu/npc/baiyi_yaofang" : 1,
        ]));

	set("cost",1);

	setup();
}

