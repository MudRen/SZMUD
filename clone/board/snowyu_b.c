// Code of ShenZhou
// /clone/snowyu/snowyu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("雪云日记本", ({ "board" }) );
        set("location", "/u/snowyu/workroom");
        set("board_id", "snowyu_b");
        set("long", "这是雪云的日记本。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
