// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("神州错别字征集处", ({ "board" }) );
set("location", "/d/city/guangchang"); 
        set("board_id", "transfer_b_new");
        set("long", "这是一个供玩家向巫师汇报神州错别字的留言版。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
