// Code of ShenZhou
// /clone/board/emei1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������Դ�", ({ "board" }) );
	set("location", "/d/emei/baoguomen");
	set("board_id", "emei1_b");
	set("long", "����һ������ɽ�ο���ʫ���Եĵط���\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

