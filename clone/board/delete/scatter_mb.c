// /clone/board/scatter_mb.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("分冥子个人留言板", ({ "board" }) );
	set("location", "/u/scatter/workroom");
	set("board_id", "scatter_mb");
	set("long", "你可以留言给分冥子, 或者是有BUG要找他帮忙\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}