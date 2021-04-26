inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"mafu ¡Ù—‘≤æ"NOR, ({ "board" }) );
        set("location", "/u/mafu/workroom");
        set("board_id", "mafu_b");
        set("long", "mafu π§◊˜¡Ù—‘≤æ\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
