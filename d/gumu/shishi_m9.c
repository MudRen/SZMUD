// July 31,2000
// Code by April
// /gumu/shishi_m9.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间十丈见方的巨大石室，空空荡荡的，什么也没有。
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao7",
		 ])
			  );

        create_door("south", "木门", "north");

	  set("cost",1);

		  setup();

}

