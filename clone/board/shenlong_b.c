// Code of ShenZhou
// /clone/board/shenlong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����̵������԰�", ({ "board" }) );
set("location", "/d/shenlong/tingkou");
	set("board_id", "shenlong_b");
	set("long", "����һ���������̽��ڽ��������԰塣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

