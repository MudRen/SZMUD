// Filename:   /d/jueqinggu/changlang1.c 长廊1
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","长廊");
		  set("long",@LONG
这是一条长长的走廊，墙壁都是用两尺厚的青石板垒筑而成。南北
墙上均匀地凿嵌着一些小洞，里面摆放着一些灯盏，把长廊照得亮堂堂
的。长廊北面是大厅，外面不远处是个大水塘。
LONG);
		  set("exits",([ 
			  "out" : __DIR__"shiwu",
			  "north" : __DIR__"dating",
			  ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}