// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������ʦ���԰�", ({ "board" }) );
	set("location", "/d/beijing/changanjie");
	set("board_id", "beijing_wb");
	set("long", "����һ�������𱱾�����ʦ���������԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
