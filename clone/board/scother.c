inherit BULLETIN_BOARD;

void create()
{
        set_name("杂项笔记板", ({ "board" }) );
        set("location", "/u/scatter/workroom/other");
        set("board_id", "scother");
        set("long", "分冥子的个人笔记。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

