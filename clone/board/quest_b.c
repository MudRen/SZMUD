//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("情节谜题留言板", ({ "board" }) );
        set("location", "/d/wizard/quest_r");
        set("board_id", "quest_b");
        set("long", "有关情节谜题问题的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}