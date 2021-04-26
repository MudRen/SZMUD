#include <ansi.h>

inherit ROOM;

void create()
{
    set( "short", HIB"调度室"NOR );
    set( "long", HIW"这里是神州开发部的调度室，开发部各组的负责巫师可以在这里向调\n"+
                    "度巫师提出人员要求。没有任务的开发巫师也可以在这提出自己想做的工\n"+
                    "作，以方便调度的需要。\n"NOR );
    set( "no_sleep_room", 1 );
    set( "non_fight", 1 );
    
    set( "exits", ([
                "east" : __DIR__"meeting_room",
                ]));
    
   call_other( "/clone/board/control_room", "???" ); 
}


            