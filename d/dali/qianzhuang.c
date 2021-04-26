// Code of ShenZhou
// Room: /d/dali/qianzhuang.c
// YZC 1995/12/04 
// LYU 1997/2/10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"钱庄"NOR);
	set("long", @LONG
此处乃大理钱庄分号儿，据说总庄在汴京，故所有存取兑和中原一般处理。
LONG
	);

	set("item_desc", ([
		"bugao" : "
汴京消息，近查获有人伪造大宋银票，故所有银票一概不收。
\n",
	]));

	set("exits", ([
		"east" : __DIR__"taihejie2",
	]));

	set("objects", ([
		__DIR__"npc/cui" : 1
	]));

	set("cost", 0);
	setup();
}

//void init()
////{
//	int balance;
//
//	if( !this_player()->query("newsaver") ) 
//	{
//		balance = this_player()->query("dali-balance");
//		if( balance >= 1000000 ) balance = balance/10;
//		if( balance >= 1000000 ) balance = 1000000;
//		this_player()->set("dali-balance", balance);
//		this_player()->set("newsaver", 1);
//	}
//	
//	this_player()->save();
//}

