// Code of ShenZhou
// /clone/board/taiyang_b.c/taiyang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(WHT"̫�����ռ�"NOR,({ "board" }) );
        set("location", "/u/taiyang/workroom");
        set("board_id", "taiyang_b");
        set("long", "����̫������ռǱ���\n" ); 
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
