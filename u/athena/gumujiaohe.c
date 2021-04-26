
// 苏梦馨(Athena) 
// Room：/u/athena/gumujiaohe.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"古木交诃"NOR);
	set("long", @LONG
古木交诃在留园的西面，一排不同图案的漏窗，使你透过漏
窗隐隐看到中部的水光山色和高低错落的楼阁，此处赏景，却有
“移步幻影”之妙。向西窗孔可以遥望绿荫轩、明瑟楼，给人一
种“庭院深深深几许”和空间不尽之感。
LONG	);
        set("exits", ([ 
	"east" : __DIR__"hehuating",
	]));
        set("objects", ([
                __DIR__"obj/yushi" : 1,
]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
