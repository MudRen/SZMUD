// Filename:   /d/jueqinggu/shiwu.c 大石屋
// Jiuer Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",WHT"大石屋"NOR);

        set("long",@LONG
行不多时，你已到了山峰顶上一处平旷之地，只见一个极大的火
堆熊熊而燃，再走近数十丈，火光下已看得明白，火堆之后有座石屋。
LONG);

        set("exits",([ 
                "south" : __DIR__"stoneroad",
                ]));
        set("objects", ([
			"/d/jueqing/npc/tongzi" : 1, 
                ]));
        
		set("no_fight" ,1);

		set("outdoors", "jueqing");
	       set("valid_startroom", 1);
        set("cost",1);  
        replace_program(ROOM);
        setup(); 
        "/clone/board/jueqing_b"->foo();
}
