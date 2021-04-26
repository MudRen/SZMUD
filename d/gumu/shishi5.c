// July 31,2000
// Code by April
// d/gumu/shishi5.c

inherit ROOM;

void create()
{
        set("short","石室");

        set("long",@LONG
这是一间普通石室，房中空空洞洞，竟和别的墓室无异。屋子一角放
了一张青石床，床上铺了张草席，一幅白布当作薄被，此外更无别物。四
壁有一些钩子，不知有什么用。
LONG);

	 set("exits",([ 
		"west" : __DIR__"mudao18",
		 ])
			  );

	 
	 set("objects", ([
		 "/kungfu/class/gumu/obj/hanyu_chuang" : 1,
		 ]));
	  
	 set("cost",1);

     setup();

}

int valid_leave(object me, string dir)
{
	if (me->query_temp("onbed")) return notify_fail("你还是先从寒玉床上下来吧！\n");

	return ::valid_leave(me, dir);
}
