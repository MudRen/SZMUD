// Code of ShenZhou
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("思念茅庐留言板", ({ "board" }) );
        set("location", "/u/missing/workroom");
	set("board_id", "miss_b");
	set("long", "这是思念专用的留言板，如果找她有事，你可以在这里留言。\n" );
	setup();
	set("capacity", 800);
	replace_program(BULLETIN_BOARD);
}

