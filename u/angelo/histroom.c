#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIW"历史资料库房"NOR);
        set("long", @LONG
这是一间很大很大的储存间里面堆满了如山似海的资料. 似乎很久没有人来打理了,
很多档案上都有着一成厚厚的灰.
LONG);
        set("exits", ([
"up" : "d/city/wumiao",
]));
    setup();
              set("no_fight", "1"); 
              set("no_steal", "1"); 
              set("no_sleep_room", "1"); 

 call_other("/clone/board/trans_b", "???");  
}
