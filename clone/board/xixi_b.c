inherit BULLETIN_BOARD;

void create()
{
	set_name("���԰�", ({ "board" }) );
	set("location", "/u/xixi/workroom");
	set("board_id", "xixi_b");
	set("long", "��λ��������СԺ�кθ��룿д����ɣ�\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}
