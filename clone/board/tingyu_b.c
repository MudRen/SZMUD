// /clone/board/tingyu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("泰山留言板", ({ "board" }) );
        set("location", "/d/taishan/tingyu");
        set("board_id", "tingyu_b");
	set("long", "这是一个设于泰山山脚下的留言板。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

