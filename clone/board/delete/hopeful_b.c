// /clone/board/hopeful_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰�", ({ "board" }) );
        set("location", "/u/hopeful/workroom");
        set("board_id", "hopeful_b");
       set("long", "����һ�������õ�ľ�塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

