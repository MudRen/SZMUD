// Code of ShenZhou
// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/huashan/pianting");
	set("board_id", "huashan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

