// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(WHT "̸���۵�" NOR, ({ "board" }) );
        set("location", "/u/karlopex/workroom");
        set("board_id", "karlopex_b");
        set("long", "����Ҷ���������ʦ���������԰塣\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
