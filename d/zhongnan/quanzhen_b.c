// Code of ShenZhou
// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���԰�", ({ "board" }) );
	set("location", "/u/sdong/zhongnan/dadian");
	set("board_id", "quanzhen_b");
	set("long", "����һ�����԰塣\n" );
	setup();
	set("capacity", 120);
	replace_program(BULLETIN_BOARD);
}

