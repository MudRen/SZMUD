//Cracked by Yujie
///d/forest/clhoulang1.c
// by yujie 10 / 2001

inherit ROOM;

#define DDR "/kungfu/class/changle/"

void create()
{
        set("short", "走廊尽头");
        set("long", @LONG
这是走廊的尽头，东边是蛇勇堂香主的私房，西边是贵宾室。前面正
对的是一重沉重的石门，里面是一个大的天然温泉场，只有香主才有权利
进去享受。
LONG );
        set("exits", ([
                "south": __DIR__"clhoulang4",
		"east" : DDR+"clsifang5",
		"west" : __DIR__"clguibin",
		
        ]));
	
             
        set("objects",([
               __DIR__"npc/cl_laopu" : 1,
               __DIR__"npc/shicong" : 1,
        ]));
        
        setup();

     
}

void init()
{	
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();
	
	if ( arg != "door")
	{	write("你要推什么？\n");
		return 1;
	}
	
	if (stringp ( me->query_temp("bangs/pos")) )
	{	message_vision("$N按动石门上的机关，石门应声而起。\n",me);
		message_vision("$N大步走了进去，石门徐徐而降。\n",me);
		me->move(__DIR__"shilu");
		tell_room(environment(me),me->name()+"大步走了进来。\n",({me}));
		return 1;
	}
	
	write("里面是长乐帮重地，只有香主以上的人才能进去，还是别乱动的好。\n");
	return 1;
}

int valid_leave(object me, string dir)
{
        object ob;
	string pos;
	
        if ( dir == "east")
        {	
                if (stringp (pos = me->query("clbpos")) && (pos != "蛇勇堂") && (me->query_temp("invite")!= "蛇勇堂"))
        		return notify_fail("这间不是你自己的私房。\n");
        		  
                if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "蛇勇堂"))
        		return notify_fail("这是蛇勇堂香主的私房，没有被邀请不得擅自闯入。\n");
        	
        	return ::valid_leave(me, dir);
	}
	
	if ( dir == "west")
        {	
                if (!stringp ( me->query("clbpos")) && !stringp (me->query_temp("bangs/pos")) )
        		return notify_fail("你又不是贵宾，不能进去。\n");
        	      		        	
        	return ::valid_leave(me, dir);
	}
		
	return ::valid_leave(me, dir);
}

