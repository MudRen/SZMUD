// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ص������԰�", ({ "board" }) );
        set("location", "/d/kunlun/sanshengtang");
        set("board_id", "kunlun_b");
        set("long", "����һ���������ɵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

