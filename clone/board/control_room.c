#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIB+"���Ȱ�"+NOR, ({ "board" }) ); 
        set("location", "/d/wizard/control_room");
        set("board_id", "control_room" );
        set("long", "���Ȱ�\n" );
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

