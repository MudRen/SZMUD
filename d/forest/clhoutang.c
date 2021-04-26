//Cracked by Yujie
///d/forest/clhoutang.c
// by yujie 10 / 2001

inherit ROOM;

void create()
{
        set("short", "后堂大门");
        set("long", @LONG
这里是长乐帮的后堂，往北就是各大香主的私房重地。一个凶神恶煞
的守卫在这里看着，闲杂人等不得进入打扰香主们的清净。
LONG );

        set("exits", ([
	       "north" : __DIR__"clhoulang1",
	       "south" : __DIR__"clhuayuan",
        ]));

	set("cost", 0);

        set("objects",([
               __DIR__"npc/cl_menwei" : 1,
        ]));
        
        set("no_fight",1);

        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "north" )
                 return ::valid_leave(me, dir);

        if( !(ob = present("men wei", environment(me))) )
                 return ::valid_leave(me, dir);

        if( !living(ob) )
                 return ::valid_leave(me, dir);
                 
           if (stringp (me->query_temp("bangs/pos"))) 
        	 return ::valid_leave(me, dir);
        	 
        if (stringp (me->query_temp("invite")))
        	return ::valid_leave(me, dir);        	

        message_vision("$N拦在$n面前，说道：里面是我帮香主们的私房重地，闲杂人等不得入内。\n", ob, me);
        return notify_fail("");
}

