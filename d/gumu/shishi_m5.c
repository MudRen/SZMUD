// July 31,2000
// Code by April
// /gumu/shishi_m5.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间二丈见方的石室，四壁光光的，什么也没有。
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao10",
		 ])
			  );

        create_door("south", "木门", "north");

	  set("cost",1);

		  setup();

}

