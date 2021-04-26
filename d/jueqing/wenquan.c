// Filename:   /d/jueqinggu/wenquan.c 温泉
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","温泉");

		  set("long",@LONG
这是一池地下温泉，泉水象是开了锅似的，向外咕嘟咕嘟地冒着热
气，温泉上迷迷蒙蒙的笼盖着一层雾气，把对面的竹林映照得飘飘渺渺
的。
LONG);

	  set("exits",([ 
		"northwest" : __DIR__"shuitang",
			 ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

