
// Filename:   /d/jueqinggu/caodi.c
// Jiuer 08/15/2001


#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short","草地");

                  set("long",
"这里是一片绿茵茵的草地，草径长两丈多，草丛四周点缀着"+HIY"鹅黄色"NOR+"
的，"+RED"胭红色"NOR+"的，"+MAG"咤紫色"NOR+"的野花，空气中散发着脉脉的花香和幽幽的青草
气息。\n"
);

	  set("exits",([ 
		"east" : __DIR__"qinghuaao1",
        "south" : __DIR__"qinghuaao6",
		"northeast" : __DIR__"qinghuaao2",
		"northwest" : __DIR__"qinghuaao4",
		]));

	  set("outdoors","jueqing");
	  set("resource/grass", 1);
	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}

