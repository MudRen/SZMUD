// July 31,2000
// Code by April
// /gumu/mudao13.c

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
		"north" : __DIR__"mudao12",
		"east" : __FILE__,
		"south" : __FILE__,
		 ])
			  );
	  set("cost",1);

		  setup();

}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg == "" ) return 0;
        if( arg == "stone" || arg == "shi") 
        {
        message_vision("$N摸索着走向南面的石墙，伸手在一块突出的青石上一按……\n\n"+
        "只听得水流阵阵，一会儿墓道中露出一个通向密道出口。\n",me);
        set("exits/down", __DIR__"midao1");
        remove_call_out("close_door");
        call_out("close_door",15,me);   
                return 1;
        }
        else
                return notify_fail("你要干什么？\n");
}

void close_door()
{
        tell_room(this_object(),"又过了一会儿，传来一阵水流声，出口被封住了。\n");
        delete("exits/down");
}
