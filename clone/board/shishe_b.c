// /clone/board/shishe_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("豪情诗社诗集", ({ "board" }) );
    set("location", "/d/wulin/shishe");
        set("board_id", "shishe_b");
	set("long", "欢迎留下大作。\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

