// Filename:   /d/jueqinggu/qinghuaao3.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"情花园"NOR);

		  set("long",@LONG
这是一片径长两丈的园形草地，外边密密层层的围满了情花。不论
从哪个方位出来，都有八九丈地面生满情花。
LONG);

	  set("exits",([ 
	  "north" : __DIR__"shulin",
	  "southeast" : __DIR__"qinghuaao2",
	  "southwest" : __DIR__"qinghuaao4"
	  		]));
	  
	  set("cost",1);
	  setup();	
}

