// Code of ShenZhou
// /u/taiyang/board_A.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("神州错别字征集处", ({ "board" }) )
        set("location", "/d/wizard/guest_room");
        set("board_id", "towiz_b")
        set("long", "这是一个供玩家向巫师报告神州错别字的地方!。\n" )
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
