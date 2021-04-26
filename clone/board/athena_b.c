// Code of ShenZhou
// /clone/board/athena_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(MAG "筑外雨楼" NOR, ({ "board" }) );
        set("location", "/u/athena/workroom");
        set("board_id", "athena_b");
        set("long", "这是苏夢馨和其他巫师交流的留言板。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
