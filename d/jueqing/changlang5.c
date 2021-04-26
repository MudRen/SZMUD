// Filename:   /d/jueqinggu/changlang5.c 长廊5
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","长廊");
		  set("long",@LONG
这是一条长长的走廊，墙壁都是用两尺厚的青石板垒筑而成。南北
墙上均匀地凿嵌着一些小洞，里面摆放着一些灯盏，把长廊照得亮堂堂
的。长廊北面飘来一股饭菜香。
LONG);
		  set("exits",([ 
			  "east" : __DIR__"changlang6",
			  "west" :__DIR__"houtang",
			  "north" : __DIR__"chufang",
			 ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}