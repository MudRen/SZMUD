// jiansu.c  board.c
// snowlf by 2001.9.30 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name( HIG"ÁôÑÔ²¾"NOR, ({ "board" }) );
	set("location", "/u/hongyan/workroom");
	set("board_id", "hongyan" );
        set("long", "ÆÆÄ¾°å¡£\n" );
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

