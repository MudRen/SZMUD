// July 31,2000
// Code by April
// /gumu/mudao8.c

inherit ROOM;

void create()
{
        set("short","墓道");

        set("long",@LONG
这阴森森的墓道，也不知道是通到哪儿的。墙上的一枝小蜡烛，正哔
哔啵啵的燃烧着。那黄晕的微光，正好照亮了这一段墓道，再远一点儿就
看不到了。墓道尽头似乎有些人声传来。
LONG);

	 set("exits",([ 
		"west" : __FILE__,
		"north" : __DIR__"mudao9",
		"east" : __DIR__"shishi_m3",
		"south" : __DIR__"mudao3",
		 ])
			  );
        create_door("east", "木门", "west");

	  set("cost",1);

		  setup();

}

