// Code of ShenZhou
// /clone/board/labuda_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�羭��", ({ "board" }) );
	set("location", "/d/xueshan/guangchang");
	set("board_id", "labuda_b");
	set("long", "����һ�������������۷��õ����԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

