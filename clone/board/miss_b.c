// Code of ShenZhou
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("˼��é®���԰�", ({ "board" }) );
        set("location", "/u/missing/workroom");
	set("board_id", "miss_b");
	set("long", "����˼��ר�õ����԰壬����������£���������������ԡ�\n" );
	setup();
	set("capacity", 800);
	replace_program(BULLETIN_BOARD);
}

