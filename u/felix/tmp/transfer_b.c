// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("玩家转站留言板", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "transfer_b");
        set("long", "这是一个供玩家提交入住「神州」申请的留言板。\n" );
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
