// July 31,2000
// Code by April
// /gumu/shishi_m4.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间三尺见方的石室，四壁光光的，什么也没有。
LONG);

	 set("exits",([ 
		"east" : __DIR__"mudao9",
		 ])
			  );

        create_door("east", "木门", "west");

	  set("cost",1);

		  setup();

}

