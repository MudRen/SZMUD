//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("物品道具留言板", ({ "board" }) );
        set("location", "/d/wizard/obj_r");
        set("board_id", "obj_b");
        set("long", "有关物品道具问题的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}