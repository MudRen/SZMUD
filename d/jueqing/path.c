// Filename:   /d/jueqinggu/path.c 小径
// Jiuer Aug 2001

#include "room.h"
inherit ROOM;
int do_drag(string arg);
void create()
{
	set("short","小径");
	set("long",@LONG
这里是小溪（river）尽头的一条小径 ，沿着小径可西行进入深谷
中，山径只有一条，倒不会行错，只是山径越行越高，也越是崎岖。从
这里可登舟一直顺流(drift)而下。
LONG);
	
	set("exits",([ 
		"westup" : __DIR__"qinghuaao1",
			 ]));

	set("raft_count", 2);
	set("item_desc", ([
		  "river" : "近岸处草丛下掩盖着一二只皮筏子(raft)，你伸手拽出一只来(drag)。\n"
	  ]));

	set("outdoors","jueqing");
	set("resource/water", 1);
	set("cost",1);
	setup();
}
void init()
{
  add_action("do_drag","drag");
}

int do_drag(string arg)
{
	object ob, me = this_player();
	if(arg=="raft")
	{ 
		if (query("raft_count") >= 1) 
		{
			me->add("jingli", -10);
			message_vision("$N从近岸处草丛下拉出一只皮筏。\n",me);
			ob = new("/d/jueqing/obj/raft2");
			ob->move("/d/jueqing/path");
			add("raft_count", -1);
         }    
   }
	else 
	{
		write("什么！");
	}
	return 1;
}
