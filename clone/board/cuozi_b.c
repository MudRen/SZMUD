// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("神州错别字征集处", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "transfer_b");
        set("long", "这是一个供玩家向巫师报告错别字的地方。\n" );
        set("poster_level", "(apprentice)");
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
