/* /kungfu/class/movie/center.c
** 神州电影院留言板
** created by yujie
** created in 11/2001
*/

inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name("神州电影院留言板", ({ "board" }) );
        set("location", "/kungfu/class/movie/center");
        set("board_id", "movie_b");
        set("long", "这是电影院专用的留言板。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

