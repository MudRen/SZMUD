// Code of ShenZhou
// /clone/board/test_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("测试组留言板", ({ "board" }) );
	set("location", "/d/wizard/test_r");
	set("board_id", "test_b");
	set("long", "这是宣布测试调查任务的留言板。\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

