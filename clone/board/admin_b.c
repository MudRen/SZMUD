//Board//8/01/2001
//by jiuer 

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW"*** "HIG"�����Ҫ��Ϣ����� "HIW"*** "NOR, ({ "board" }) );
        set("location", "/d/wizard/meeting_room");
        set("poster_level", "(admin)");
        set("board_id", "admin_b");
        set("long", "��۷�����վ��Ҫ��������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}