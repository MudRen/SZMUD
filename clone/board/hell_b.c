// /clone/board/hell_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���Բ�", ({ "board" }) );
	set("location", "/u/huaishi/hell");
	set("board_id", "hell_b");
	set("long", "����һ�����԰塣\n" );
	set("wizard_only", 1);
	setup();
	set("capacity", 1000);
	replace_program(BULLETIN_BOARD);
}

