// /clone/board/shishe_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ʫ��ʫ��", ({ "board" }) );
    set("location", "/d/wulin/shishe");
        set("board_id", "shishe_b");
	set("long", "��ӭ���´�����\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

