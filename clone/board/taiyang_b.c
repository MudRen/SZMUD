// Code of ShenZhou
// /clone/board/taiyang_b.c/taiyang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(WHT"太阳神日记"NOR,({ "board" }) );
        set("location", "/u/taiyang/workroom");
        set("board_id", "taiyang_b");
        set("long", "这是太阳神的日记本。\n" ); 
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
