
// Filename:   /d/jueqinggu/shiwu1.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
	set("short","小石屋");

	set("long",@LONG
这里有一座小石头屋子，是给干活、寻山的家丁和过往的客人们歇
脚夜宿而设的。
LONG);

	  set("exits",([ 
		  "west" : __DIR__"shulin",
		  ]));

	  set("cost",1);
	  set("outdoors","jueqing");
	  setup();	
	  replace_program(ROOM);
}

