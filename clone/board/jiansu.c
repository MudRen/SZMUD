// jiansu.c  board.c
// snowlf by 2001.9.30 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW+"����"+NOR, ({ "jian su", "silk", "board" }) ); 
        set("location", "/u/snowlf/workroom");
        set("board_id", "jiansu");
        set("long", "����˫˿֯�ɣ������黭�õİ�ɫϸ������������ı��������õġ�\n" );
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

