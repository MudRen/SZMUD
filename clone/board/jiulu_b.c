// /clone/board/jiulu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("¿ñ·Å¾ÆÛäÆÃÄ«´¦", ({ "board" }) );
        set("location", "/d/wulin/jiulu");
        set("board_id", "jiulu_b");
        set("long", "»¶Ó­¾ÆºóÆÃÄ«¡£\n" );
        setup();
        set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}

