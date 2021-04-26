// Filename:   /d/jueqinggu/changlang4.c 长廊4
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","长廊");
		  set("long",@LONG
这是一条长长的走廊，墙壁都是用两尺厚的青石板垒筑而成。南北
墙上均匀地凿嵌着一些小洞，里面摆放着一些灯盏，把长廊照得亮堂堂
的。长廊北面是间书房，东边是后堂。
LONG);
		  set("exits",([ 
		      "east" : __DIR__"houtang",
			  "west" : __DIR__"changlang3",
			  "north" : __DIR__"shufang",
			 ]));
		  
		  create_door("north", "木门", "south");
		  set("cost",1);
		  setup();	
		  replace_program(ROOM);
}