// Filename:   /d/jueqinggu/shuitang.c
// Jiuer - Aug 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",CYN"水仙塘"NOR);

	set("long",@LONG
一阵清香涌至，眼前无边无际的全是水仙花。原来这地下是浅浅的
一片水塘(tang)，深不逾尺，种满了水仙。你好生奇怪，这水仙花儿是
南方之物，不知何以竟会在关洛之间的山顶出现。
LONG);

	set("exits",([ 
		"southwest" : __DIR__"zhulin",
		"southeast" : __DIR__"wenquan",
		]));
	  
	set("item_desc", (["tang" : 
		"水塘中每隔四五尺便是一个木桩(muzhuang)。\n"]));
	set("resource/water", 1);
	set("outdoors","jueqing");
	set("cost",2);

	setup();	
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if(!arg || arg != "muzhuang")
		return notify_fail("你要干什么? \n");
	
	message_vision("$N纵身往木桩上跳去。\n", me);
	
	if ( me->query_skill("dodge",1) <= 20 ) 
	{	
		message_vision("$N脚下一磕，一头撞在木桩上。\n", me);
		me->unconcious(); 
	}
    
	if ( me->query_skill("dodge",1) > 20 && me->query_skill("dodge",1) <= 50 ) {
		message_vision("$N一下没跳过去还踏倒了几根木桩。\n", me);
            }

	if ( me->query_skill("dodge",1) > 50 ) 
	{
		me->move(__DIR__"stoneroad");
		message("vision", me->name() + 
			"身形微幌，纵跃踏桩而过。\n",environment(me), ({me}) );
	}
		return 1;	
}		
