//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("雪山笔记板", ({ "board" }) );
        set("location", "/u/scatter/workroom/xs");
        set("board_id", "scxs");
        set("long", "分冥子的个人笔记。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

