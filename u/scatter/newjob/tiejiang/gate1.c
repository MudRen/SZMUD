                          //code by cheap
//11/10/01

//Modify by Scatter
//V 1.1

#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short",HIC"矿场入口"NOR);
        set("long",
"这里是矿场的入口，从外面望进去，里面一片黑暗。静静地细听，你会不时\n"
"听到“滴答”“滴答”的滴水声。里面也蛮恐怖，听人说里面好像有猛鬼，因为\n" 
"好久以前在这里曾有人自杀,所以很多人都不愿意单人进去。\n " 
        ); 

        set("outdoors","city");
// ***** NPC ADDED BY SCATTER *****
        set("objects", ([
                __DIR__"npc/manage" : 1,
        ]));



        set("exits", ([ 
        "west":"/newjob/tiejiang/room.c", 
        "east":"/newjob/tiejiang/gate.c",
        "enter":"/newjob/tiejiang/kuangchang.c",
        "northdown":"/d/dali/minov54.c",
                "south" : "/d/xingxiu/silk3.c",

        ])); 
        
        setup();
//       replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
        if( (!me->query_temp("kuangchang/enter")) && (dir == "enter"))
          { 
            return notify_fail("你还没得到主管同意呢。\n");
          }
        return ::valid_leave(me, dir);
}

