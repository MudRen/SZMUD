// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("北京巫师留言板", ({ "board" }) );
	set("location", "/d/beijing/changanjie");
	set("board_id", "beijing_wb");
	set("long", "这是一个供负责北京的巫师交流的留言板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
