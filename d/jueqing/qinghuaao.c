
// Filename:   /d/jueqinggu/qinghuaao.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"情花园"NOR);

		  set("long",@LONG
这是一片径长两丈的园形草地，外边密密层层的围满了情花。不论
从那个方位出来，都有八九丈地面生满情花。
LONG);

	  set("exits",([ 
		"northwest" : __DIR__"zhulin",
		"east" : __DIR__"caodi",
		"eastdown" : __FILE__,
		"north" : __FILE__,
		"southwest" : __DIR__"shiwu1",
	    "west" : __DIR__"shulin",
		]));
	  
	  set("cost",1);
	  setup();	
}

