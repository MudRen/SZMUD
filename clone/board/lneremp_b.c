//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
          set_name("门派留言板", ({ "board" }) );
          set("location", "/d/wizard/lneremenpai");
        set("poster_level", "(wizard)");
        set("board_id", "devide_b");
        set("long", "天帝首席开发神仙宣布分工分组的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
