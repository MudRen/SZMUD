// Code of ShenZhou
// /clone/board/changle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�³��ְ����԰�", ({ "board" }) );
	set("location", "/d/forest/clzoulang2");
	set("board_id", "changle_b");
	set("long", "���ǹ���ʦ�޸ĳ��ְ��õĹ������԰塣\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

