// Filename:   /d/jueqinggu/shishi2.c 石室2
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","石室");
		  set("long",@LONG
这是一间不大的石室，里面只摆放一张木制大桌，桌上放了些骨针
和麻线，墙上挂着些绿色的渔网。石室的西面是大厅，时不时传来阵阵
的打闹声。
LONG);
		  set("exits",([ 
			  "west" : __DIR__"dating",
			 ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}