// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(WHT "谈经论道" NOR, ({ "board" }) );
        set("location", "/u/karlopex/workroom");
        set("board_id", "karlopex_b");
        set("long", "这是叶枫和其他巫师交流的留言板。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
