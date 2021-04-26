// Filename:   /d/jueqinggu/path.c С��
// Jiuer Aug 2001

#include "room.h"
inherit ROOM;
int do_drag(string arg);
void create()
{
	set("short","С��");
	set("long",@LONG
������СϪ��river����ͷ��һ��С�� ������С�������н������
�У�ɽ��ֻ��һ�����������д�ֻ��ɽ��Խ��Խ�ߣ�ҲԽ����᫡���
����ɵ���һֱ˳��(drift)���¡�
LONG);
	
	set("exits",([ 
		"westup" : __DIR__"qinghuaao1",
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
			ob = new("/d/jueqing/obj/raft2");
			ob->move("/d/jueqing/path");
			add("raft_count", -1);
         }    
   }
	else 
	{
		write("ʲô��");
	}
	return 1;
}
