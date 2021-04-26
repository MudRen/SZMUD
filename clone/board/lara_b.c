// Code of ShenZhou
// /clone/board/lara_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("探墓手记", ({ "board" }) );
        set("location", "/u/lara/workroom");
        set("board_id", "lara_b");
        set("poster_level", "(apprentice)");
        set("long", "这是供巫师贴告示用的，玩家不能张贴。\n");
        set("intermud", 1);
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}

