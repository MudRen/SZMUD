// Code of ShenZhou
// /clone/board/test_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������԰�", ({ "board" }) );
	set("location", "/d/wizard/test_r");
	set("board_id", "test_b");
	set("long", "�����������Ե�����������԰塣\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

