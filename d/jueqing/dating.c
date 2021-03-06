// Filename:   /d/jueqinggu/dating.c 大厅
// Program:    Jiuer
// Date:       Aug 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short","大厅");
	set("long",@LONG
走进石屋的大厅，这里极为开阔，北面正首一把靠椅、一张茶桌，
靠椅后面立一雕花屏风，西首一排座椅，大厅内一切陈设均是绿色。
大厅内矗立四根大石柱，柱顶有四根横梁相接。
LONG);
	
	set("objects", ([
		CLASS_D("jueqing") + "/gongsun" : 1,
               __DIR__"npc/zhang" : 1,
		]));

	set("exits",([ 
		"east" : __DIR__"shishi2",
		"west" : __DIR__"changlang2",
		"south" : __DIR__"changlang1",
		"north" : __DIR__"houtang",
		]));

	set("cost",1);
	setup();
	replace_program(ROOM);
}
