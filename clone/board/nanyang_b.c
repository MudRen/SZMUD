// Code of ShenZhou
// /clone/board/nanyang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/shaolin/kedian1");
	set("board_id", "nanyang_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

