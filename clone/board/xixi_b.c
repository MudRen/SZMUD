inherit BULLETIN_BOARD;

void create()
{
	set_name("留言板", ({ "board" }) );
	set("location", "/u/xixi/workroom");
	set("board_id", "xixi_b");
	set("long", "各位看了甜心小院有何感想？写在这吧！\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}
