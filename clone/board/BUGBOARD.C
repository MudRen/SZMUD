// /clone/board/bugboard.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("BUG ���԰�", ({ "board" }) );
	set("location", "/d/city/guangchang");
	set("board_id", "bugboard");
	set("long", "��� BUG POST ����, ��ϸ������ read 1" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
