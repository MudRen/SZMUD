inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"mafu ���Բ�"NOR, ({ "board" }) );
        set("location", "/u/mafu/workroom");
        set("board_id", "mafu_b");
        set("long", "mafu �������Բ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
