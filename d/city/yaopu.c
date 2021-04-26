// Code of ShenZhou
// Room: /city/yaopu.c
// YZC 1995/12/04 

//#include <room.h>   
#include <ansi.h>   
inherit ROOM;

//void close_path(); 

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小抽
屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。一名
小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG
	);
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		]));

	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
		金创药：\t五两白银
		蛇　药：\t二两白银
		养精丹：\t壹两白银
		其他神药与老板面议。\n",
		]));

//	set("item_desc", ([
//		"guanggao" : "本店老板平一指外出采药未归，今日暂停营业。\n",
//	]));

	set("objects", ([
		__DIR__"npc/ping" : 1,
                __DIR__"npc/huoji" : 1,
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
}
/*
void init() 
{
	add_action("do_open", "open"); 
}

int do_open(string arg)
{
	object me; 
	me = this_player(); 
	if( !arg || arg=="" ) return 0; 
	if( arg=="door" ) {
		write(HIW"你一个箭步上去,想轻轻推开那扇门。\n"NOR); 
		return 1;
	}
	if( me->query("id") == "surf" || "leiidian" ) {
		write(HIY"结果出现了一个入口。\n"NOR);
		return 1;
	}
	if( !query("exits/up") ) { 
		set("exits/up", __DIR__"surf_room");
		call_out("close_path", 3);
		return 1;
	}
	else {
		write(HIY"没有天魔和凌波舟的指令我能让你进吗？\n"NOR); 
		message_vision( HIR "突然门逢中涌出一阵白色的烟雾，$N不由地深吸了一口气。忽然感觉到一阵恶心,还是赶快走吧!\n\n\n" NOR,me); 
		return 1;
	}
	write("你要移动什么？\n"); 
	return 0;
}
void close_path() 
{
	if( !query("exits/up") ) return;
	message("vision", HIW"你的眼前一亮，难道我真的可以见到神医吗？\n"NOR,this_object() ); 
	delete("exits/enter"); 
}
*/
