// jiansu.c  board.c
// snowlf by 2001.9.30 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW+"缣素"+NOR, ({ "jian su", "silk", "board" }) ); 
        set("location", "/u/snowlf/workroom");
        set("board_id", "jiansu");
        set("long", "采用双丝织成，供作书画用的白色细绢，供来沁涟宫的宾客留言用的。\n" );
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

