// July 31,2000
// Code by April
// /gumu/dating.c
// Update April 01.08.24

inherit ROOM;

void create()
{
	set("short","大厅");

	set("long",@LONG
这间大厅布置的极为简单，几张木椅和几张桌子放在正当中，靠墙的
一个小柜子上点着一只小三脚香炉，飘出来的袅袅轻烟带着一股香味。这
味道浓而不腻，令人有一股飘飘然的感觉。厅中的柱上插了几枝巨烛，把
房间照的明晃晃的。
LONG);

	set("exits",([ 
		"west" : __DIR__"mudao15",
		"south" : __DIR__"mudao1",
		"east" : __DIR__"mudao2",
		"north" : __DIR__"mudao14",
		]) );
	
	set("cost",1);
    set("no_fight",1);
      set("valid_startroom", 1);

    set("objects",([
      ]));

	setup();
	 "/clone/board/gumu_b"->foo();
}
