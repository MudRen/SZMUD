// Code of ShenZhou
// /clone/board/guide_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("代码问题讨论板",({"board"}));
	set("location", "/d/wizard/guide_r");
	set("board_id", "guide_b");
	set("long", "这是供大家讨论编程相关问题的留言板.\n");
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

