// Filename:   /d/jueqinggu/huowanshi.c
// Jiuer 8/2001


inherit ROOM;

void create()
{
		  set("short","������");

		  set("long",@LONG
Խ��ש�ڣ�����ӭ������������ֹ����ڰ�Ѳ�̿����ʱ�䵱�Ϻ���
������ȴ����ಲ������ֻ��һ��ţͷ�̿㣬أ��ȫ������졣��ǽ
����һ��ͻ���Ĵ�ʯ(stone)���������е��ɶ���			
LONG);

	  set("exits",([ 
		  "east" : __DIR__"shiliang",
		  "up" : __DIR__"yutree",
		  ]));

	  set("objects" , ([
		  __DIR__"npc/jiading" : 1,
		  ]));

	  set("item_desc", (["stone" :"����һ���ʯ�顣\n"]));
	  set("cost",1);
	  setup();	
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!arg ||arg != "stone")
		return 0;
	
	if(arg=="stone"||arg=="shi")
	{
		message_vision("$N���˲�ע�⣬���ĵذ�ʯש����һ�飬һ��ʯ�������ش��ˡ�\n",me);
	
		set("exits/enter",__DIR__"shishi4");

		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;	
	}		
	else
	
		return notify_fail("��Ҫ��ʲô \n");	
}


void close_door()
{
   tell_room(this_object(),"����һ�����ʯ��������һ�¹����ˡ�\n");
   delete("exits/enter");
}


int valid_leave(object me, string dir)
{
	if ((dir == "enter")&& !wizardp(me)) 
	{   
		if (objectp(present("jiading", environment(me))))
			return notify_fail("�����˵�ס�����ȥ·��������������˵�һ�ɲ������ڡ�\n");
	}
	return ::valid_leave(me, dir);
}