// Code of ShenZhou
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�һ����������԰�",({"board"}));
	set("location", "/d/taohua/jingshe");
	set("board_id", "taohua_b");
	set("long", "���ǹ��һ������˽����ļ��°�.\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

