// board.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name("ɳĮ֮�����԰�", ({ "board" }) );
        set("location", "/u/smzz/workroom");
        set("board_id", "smzz_b");
        set("long", "�ҹ�ˮ�ߴ���ʮ�˲������\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

