// Filename:   /d/jueqinggu/zhulin.c
// Program:    Jiuer
// Date:       Aug 15, 2001

inherit ROOM;

void create()
{
		  set("short","竹林");

		  set("long",@LONG
你向山后走来，行出里许，忽见迎面绿油油的好大一片竹林。北方
竹子极少，这般大的一片竹林更是罕见。在绿竹篁中穿过闻到一阵阵淡
淡花香，登觉烦俗尽消。
LONG);

	  set("exits",([ 
		"southdown" : __DIR__"shulin",
		"northeast" : __DIR__"shuitang",
			 ]));
	  	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();
	  replace_program(ROOM);
}

