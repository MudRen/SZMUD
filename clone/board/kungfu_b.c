//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("功夫技能留言板", ({ "board" }) );
        set("location", "/d/wizard/kungfu_r");
        set("board_id", "scatter_mb");
        set("long", "有关功夫技能问题的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}