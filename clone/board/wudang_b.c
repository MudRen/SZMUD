// Code of ShenZhou
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������", ({ "board" }) );
	set("location", "/d/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long", "����һ�����ͼ����ʯ�����׳ơ����Ա�����\n"
	            "�����м�¼������䵱�����Ĵ�С�¼���\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

