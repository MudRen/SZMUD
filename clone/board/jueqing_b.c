// /clone/board/jueqing_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("留言板", ({ "board" }) );
        set("location", "/d/jueqing/shiwu");
        set("board_id", "jueqing_b");
        set("long", "一块四周雕有情花的大木牌子。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

