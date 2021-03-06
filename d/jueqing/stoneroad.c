// Filename:   /d/jueqinggu/stoneroad.c
// Jiuer   08/2001

inherit ROOM;

void create()
{
	set("short","青石板路");

	set("long",@LONG
一条笔直的青石板小路。路边栽植奇花异草，四周草木青翠欲滴，
繁花似锦，一路上已是风物佳胜，信步而行，只见路旁仙鹤三二、白鹿
成群，松鼠小兔，尽是见人不惊。南面是个大水塘(tang)。
LONG);
	
	set("exits",([ 
		"north" : __DIR__"shiwu",
		"west" : __DIR__"shanlu4",
		]));

	set("item_desc", (["tang" : 
			"水塘中每隔四五尺便是一个木桩(jump muzhuang)。\n"]));
	
	set("objects",([
		__DIR__"npc/squirrel" : 1,
		]));

	set("outdoors","jueqing");
	set("cost",1);
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
		me->move(__DIR__"shuitang");
		message("vision", me->name() + 
			"身形微幌，纵跃踏桩而过。\n",environment(me), ({me}) );
	}
		return 1;	
}		
