// Code of ShenZhou
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����������԰�", ({ "board" }) );
	set("location", "/d/wuguan/zhengting");
	set("board_id", "wuguan_b");
	set("long", "����һ��������ӵܽ��������԰塣\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}

