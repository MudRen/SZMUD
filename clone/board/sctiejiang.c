//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("铁匠笔记板", ({ "board" }) );
        set("location", "/u/scatter/workroom/tiejiang");
        set("board_id", "sctiejiang");
        set("long", "分冥子的个人笔记。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

