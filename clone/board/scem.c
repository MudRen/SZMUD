inherit BULLETIN_BOARD;

void create()
{
        set_name("峨嵋笔记板", ({ "board" }) );
        set("location", "/u/scatter/workroom/em");
        set("board_id", "scem");
        set("long", "分冥子的个人笔记。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

