// Filename:   /d/jueqinggu/shufang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		set("short","书房");
		set("long",@LONG
这儿是水仙庄庄主的书房，存放着家族一百年来收藏的书籍和经册，
只见靠墙是一排书架，摆满了道教的典籍。中央有一个长方形的大桌子，
上面放着两本道书。一个家丁正在打扫书房。
LONG);

	  set("exits",([ 
		"south" : __DIR__"changlang4",
		]));
	  
	  create_door("south", "木门", "north");

	  set("objects",([ 
		  "/d/zhongnan/obj/daodejing" : 1,
		  "/d/zhongnan/obj/daodejing-i" : 1,
		  __DIR__"npc/jiading" : 1,
		  ]));

	  set("cost",1);
	  setup();
	  replace_program(ROOM);
}

