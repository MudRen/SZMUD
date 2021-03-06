// Filename:   /d/jueqinggu/river.c 小溪
// Jiuer Aug 15, 2001

#include "room.h"

inherit ROOM;
int do_drag(string arg);
void create()
{
		  set("short","小溪");

		  set("long",@LONG
这是一条顺山谷奔流而下的小溪，时而湍急，时而缓行，溪流曲折，
水花拍打两岸的岩石，哗哗声回荡山谷中。溪面(river)不宽，但要船儿
逆流而上，实在是件不易的事情。
LONG);

	  set("exits",([ 
		  "eastdown" : "/d/shaolin/shandao",
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
			ob = new("/d/jueqing/obj/raft");
			ob->move("/d/jueqing/river");
			add("raft_count", -1);
         }    
   }
	else 
	{
		write("什么！");
	}
	return 1;
}
