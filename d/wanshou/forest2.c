// Code of ShenZhou
// /d/wanshou/forest2.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void reset_path(object me);
void check_out(object me);

void create()
{
        set("short", "密林");
        set("long", @LONG
这一片树林树木茂密，遮天蔽日，有如树海，无边无际。黑暗
中就会有什么鬼魅突如其来，将你攫去似的。你面对着这一片广阔
无边、阴沉黑暗的树林不由一阵胆寒，看来还是赶快退出去的好。
LONG
        );
        set("exits", ([
				"north" : __DIR__"forest5",
				"south" : __DIR__"forest8",
				"east" : __DIR__"forest3",
				"west" : __DIR__"forest1",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}

void  init()
{              
	object  me=this_player();

	if(  me->query_temp("tree2")  ==  0  )
	{
		me->set_temp("tree2",  1);
	}
	else  if(  me->query_temp("tree2")  ==  1  )
	{
		reset_path(me);
	}
	
	if(  check_out(me)  )
	{  
        set("exits/south", __DIR__"forest0");
        call_out("close_exit_forest", 5);
	}
}

void close_exit_forest()
{
       set("exits/south", __DIR__"forest8");
}

void  reset_path(object me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i)  )     	   
   	        me->delete_temp("tree"+i);
	}
	return;
}

int  check_out(object  me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i) != 1 )     	   
		  return 0;
	}
	reset_path(me); 
	return 1;
}
