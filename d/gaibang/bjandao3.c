// by Jiuer 
// Room: /d/gaibang/bjandao2.c  北京暗道
// Date:  03/15/2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮 极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
	);

	set("exits", ([
			"up" : "/d/beijing/tianqiao",
			"south" : __DIR__"bjandao2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
