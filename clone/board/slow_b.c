// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("slow留言板", ({ "board" }) );
        set("location", "/d/wizard/slowroom");
         set("board_id", "slow_b");
        set("long", "这是一个供神州武功交留的留言板。\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

