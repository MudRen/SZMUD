// July 31,2000
// Code by April
// /gumu/shishi1.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间普通石室，四壁有一些钩子，不知有什么用。
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao17",
		 ])
			  );

        create_door("south", "木门", "north");

	  set("cost",1);

		  setup();

}

