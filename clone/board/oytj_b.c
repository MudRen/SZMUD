// Code of ShenZhou
// /clone/board/oytj_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIW "如果蓝色" NOR, ({ "board" }) );
        set("location", "/u/oytj/workroom");
        set("board_id", "oytj_b");
        set("long", "这是彩虹和其他巫师交流的留言板,有什么特殊的事也请留言吧。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
