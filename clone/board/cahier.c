// cahier.c  board for meeting_room.c
// snowlf by 2001.10.23 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW+"备忘录"+NOR, ({ "cahier","book","board" }) ); 
        set("location", "/u/snowlf/room/meeting_room");
        set("board_id", "cahier");
        set("long", "一个精致的小记事本，封面上写著"+HIW+"【备忘录】"+NOR+"三个字，这是本组的工作记要，没事请不要在上面乱写乱画哦！\n" );
        setup();
        set("capacity", 600); 
        replace_program(BULLETIN_BOARD);
}

