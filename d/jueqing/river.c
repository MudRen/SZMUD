// Filename:   /d/jueqinggu/river.c СϪ
// Jiuer Aug 15, 2001

#include "room.h"

inherit ROOM;
int do_drag(string arg);
void create()
{
		  set("short","СϪ");

		  set("long",@LONG
����һ��˳ɽ�ȱ������µ�СϪ��ʱ���ļ���ʱ�����У�Ϫ�����ۣ�
ˮ���Ĵ���������ʯ���������ص�ɽ���С�Ϫ��(river)������Ҫ����
�������ϣ�ʵ���Ǽ����׵����顣
LONG);

	  set("exits",([ 
		  "eastdown" : "/d/shaolin/shandao",
		]));
	  
	  set("raft_count", 2);
	  
	  set("item_desc", ([
		  "river" : "�������ݴ����ڸ���һ��ֻƤ����(raft)��������ק��һֻ��(drag)��\n"
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
			message_vision("$N�ӽ������ݴ�������һֻƤ����\n",me);
			ob = new("/d/jueqing/obj/raft");
			ob->move("/d/jueqing/river");
			add("raft_count", -1);
         }    
   }
	else 
	{
		write("ʲô��");
	}
	return 1;
}
