#include <ansi.h>

inherit ROOM;

void create()
{
    set( "short", HIG"曲院风荷"NOR );
    set( "long", "走进亭院，只见临湖一座小榭。柱上有一对联(duilian)。 依榭"+
                "\n观湖，只见荷花满湖，茭荷深处，香远益清。\n"NOR );
    set( "no_fight", 1 );
    call_other( "/clone/board/hongyan", "???" );
}
