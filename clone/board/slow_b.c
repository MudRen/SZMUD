// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("slow���԰�", ({ "board" }) );
        set("location", "/d/wizard/slowroom");
         set("board_id", "slow_b");
        set("long", "����һ���������书���������԰塣\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

