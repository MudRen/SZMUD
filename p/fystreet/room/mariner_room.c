//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 600
inherit ROOM;
void create()
{       
    set( "short" , HIC"С��"NOR );
    set( "long",
@LONG
[1;37m
       _~
    _~ )_)_~
    )_))_))_)   [37;0m
[1;34m    _!__!__!__
    \_______t/
[34m[46;1m[5m  ~~~[37;0m[34m[46;1m~~~~~~~~~~~~[5m~~ 
[37;0m    
LONG
    );
    set( "exits",([
         "out" : "/p/fystreet/street"+(string)ID,
         "up" : "/u/mariner/musicroom2",
        ]));
    set("owner","mariner");
    set("no_fight",1);
    set("no_magic",1);
    set("sleep_room",1);
    set("if_bed",1);
    set("NONPC",1);
    set("no_dazuo",1);
    set("no_study",1);
    set("coor/x",40+(ID%2)*20);
    set("coor/y",20+(ID/100)*10);
    set("coor/z",0);
    setup();
    call_other("/p/fystreet/board/mariner_board","???");
}
#include "indoor_func.c"
