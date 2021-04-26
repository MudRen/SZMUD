
// 苏梦馨(Athena) 
// Room：/u/athena/liuyuan.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"留园"NOR);
	set("long", @LONG
留园是苏州的一大名景之一，它以结构布局紧密、厅堂华丽
宏敝、装饰精美典雅而享有“吴中第一名园”之誉。
LONG	);
        set("exits", ([ 
	"west" : __DIR__"hehuating",
	"north" : __DIR__"zhibaixuan",
        "south"  : "u/athena/workroom", 
        "east" : __DIR__"shizilin",
	]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

