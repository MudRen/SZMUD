// Code of ShenZhou
// /clone/board/xuanjie_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ٽ����԰�", ({ "board" }) );
	set("location", "/d/qilian/datang");
	set("board_id", "xuanjie_b");
	set("long", "����һ�������ٽ̽��ڽ��������԰塣\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

