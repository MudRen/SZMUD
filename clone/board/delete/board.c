// Code of ShenZhou
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("���˱�", ({ "board" }) );
	set("location", "/d/xingxiu/btyard");
	set("board_id", "baituo_b");
        set("long", "��ʲôʱҪ���Ҳ���������һ��post��\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

