// July 31,2000
// Code by April
// /gumu/shishi_m7.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间四丈见方的石室，四壁光光的，什么也没有。
LONG);

	 set("exits",([ 
		"north" : __DIR__"mudao5",
		 ])
			  );

     create_door("north", "木门", "south");

	  set("cost",1);

		  setup();

}

