//白驼工具房 toolroom.c
//by spark 5/24/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","工具房");
	set("long",@LONG
这是一个宽敞明亮的房间，摆放了一个大木架(jia)和一些零碎的小物
品。木架上陈列着很多奇形怪状的工具。
LONG
	);
	set("exits",([
		"northwest": __DIR__"kongdi2",
		]));

	set("cost",1);
	setup();
   	replace_program(ROOM);
}
