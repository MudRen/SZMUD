// July 31,2000
// Code by April
// /gumu/shishi_m1.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间三尺见方的石室，四壁光光的，什么也没有。
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao2",
		 ])
			  );

        create_door("south", "木门", "north");

	  set("cost",1);

		  setup();

}

