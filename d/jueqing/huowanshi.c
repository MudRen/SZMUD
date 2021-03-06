// Filename:   /d/jueqinggu/huowanshi.c
// Jiuer 8/2001


inherit ROOM;

void create()
{
		  set("short","火烷室");

		  set("long",@LONG
越过砖壁，热浪迎面而来。两名粗工正在搬堆柴炭，此时虽当严寒，
这两人却上身赤膊，下身只穿一条牛头短裤，兀自全身大汗淋漓。西墙
上有一块突出的大石(stone)，好象能有点松动。			
LONG);

	  set("exits",([ 
		  "east" : __DIR__"shiliang",
		  "up" : __DIR__"yutree",
		  ]));

	  set("objects" , ([
		  __DIR__"npc/jiading" : 1,
		  ]));

	  set("item_desc", (["stone" :"这是一块大石块。\n"]));
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
		message_vision("$N趁人不注意，悄悄地把石砖往外一抽，一道石门慢慢地打开了。\n",me);
	
		set("exits/enter",__DIR__"shishi4");

		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;	
	}		
	else
	
		return notify_fail("你要干什么 \n");	
}


void close_door()
{
   tell_room(this_object(),"过了一会儿，石门又咔喳一下关上了。\n");
   delete("exits/enter");
}


int valid_leave(object me, string dir)
{
	if ((dir == "enter")&& !wizardp(me)) 
	{   
		if (objectp(present("jiading", environment(me))))
			return notify_fail("绿衣人挡住了你的去路：谷主有令，闲杂人等一律不得入内。\n");
	}
	return ::valid_leave(me, dir);
}