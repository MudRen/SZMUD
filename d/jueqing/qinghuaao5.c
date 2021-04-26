// Filename:   /d/jueqinggu/qinghuaao5.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
		  set("short",HIM"情花园"NOR);

		  set("long",@LONG
这是一片径长两丈的园形草地，外边密密层层的围满了情花。不论
从哪个方位出来，都有八九丈地面生满情花。
LONG);

	  set("exits",([ 
		"northeast" : __DIR__"qinghuaao4",
		"southeast" : __DIR__"qinghuaao6",
		"westup" : __DIR__"shiliang",
		]));
	  
	  set("objects", ([ 
		  "/d/jueqing/npc/jiading" : 1,
		  ]));

	  set("cost",1);
	  setup();	
}

int valid_leave(object me, string dir)
{
	if ((dir == "westup")&& !wizardp(me)) 
	{   
		if (objectp(present("jiading", environment(me))))
			return notify_fail("绿衣人挡住了你的去路：谷主有令，闲杂人等一律不得入内。\n");
	}	
//	message_vision(HIR"情急之中，你用手拨开花丛想穿过花丛，手指却被花朵背后隐藏小刺刺损了。\n\n"NOR,me);
//	me->apply_condition("qh_poison",10);

	return ::valid_leave(me, dir);
}
