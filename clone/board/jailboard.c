// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ʸ����԰�", ({ "board" }) );
	set("location", "/u/scatter/jail/jail.c");
	set("board_id", "jailboard");
	set("long", "���ֵ�ɣ�д�ڹ����\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
