// /clone/board/scatter_mb.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ڤ�Ӹ������԰�", ({ "board" }) );
	set("location", "/u/scatter/workroom");
	set("board_id", "scatter_mb");
	set("long", "��������Ը���ڤ��, ��������BUGҪ������æ\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}