// cahier.c  board for meeting_room.c
// snowlf by 2001.10.23 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW+"����¼"+NOR, ({ "cahier","book","board" }) ); 
        set("location", "/u/snowlf/room/meeting_room");
        set("board_id", "cahier");
        set("long", "һ�����µ�С���±���������д��"+HIW+"������¼��"+NOR+"�����֣����Ǳ���Ĺ�����Ҫ��û���벻Ҫ��������д�һ�Ŷ��\n" );
        setup();
        set("capacity", 600); 
        replace_program(BULLETIN_BOARD);
}

