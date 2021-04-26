// jiansu.c  board.c
// snowlf by 2001.9.30 

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIB+"ÀÆ ÷¡Ù—‘≤æ"+NOR, ({ "board" }) ); 
	set("location", "/u/mariner/workroom");
	set("board_id", "mariner" );
        set("long", "∆∆ƒæ∞Â°£\n" );
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

