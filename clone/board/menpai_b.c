// Code of ShenZhou
// /clone/board/menpai_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("门派组留言板", ({ "board" }) );
        set("location", "/d/wizard/smiling_room");
        set("board_id", "progress_b");
        set("long", "这是一个供门派组巫师们交流的留言板。\n" );
        set("wizard_only", 1);
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
