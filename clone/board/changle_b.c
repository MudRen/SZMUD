// Code of ShenZhou
// /clone/board/changle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("新长乐帮留言板", ({ "board" }) );
	set("location", "/d/forest/clzoulang2");
	set("board_id", "changle_b");
	set("long", "这是供巫师修改长乐帮用的工作留言板。\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

