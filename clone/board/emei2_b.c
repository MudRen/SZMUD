// Code of ShenZhou
// /clone/board/emei2_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ҵ������԰�", ({ "board" }) );
	set("location", "/d/emei/hz_guangchang");
	set("board_id", "emei2_b");
	set("long", "����һ�������ҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

