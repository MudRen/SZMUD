// /clone/board/tingyu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("̩ɽ���԰�", ({ "board" }) );
        set("location", "/d/taishan/tingyu");
        set("board_id", "tingyu_b");
	set("long", "����һ������̩ɽɽ���µ����԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

