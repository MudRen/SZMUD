// board.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIY "留言板" NOR, ({ "board"}) );
        set("location", "/p/fystreet/room/keny_room.c");
        set("board_id", "keny_board");
        set("no_post",1);
        set("long",     "这是一个个人留言板，如果房间主人不在，你可以在这里留言。\n");
	setup();
        set("capacity", 99);
	replace_program(BULLETIN_BOARD);
}
