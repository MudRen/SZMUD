// Code of ShenZhou
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ձ�", ({ "board" }) );
        set("location", "/d/baituo/btyard");
	set("board_id", "baituo_b");
	set("long", "����һ�����ɽׯ�ӵ������õ�ʯ����\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

