// /clone/board/wulin_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("武林札记", ({ "board" }) );
        set("location", "/d/wulin/xiaowu");
        set("board_id", "wulin_b");
        set("poster_level", "(player)");
        set("long", "这是武林同盟盟主的私人留言簿，欢迎多提建议。\n");
        set("intermud", 1);
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

