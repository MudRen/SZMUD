// Code of ShenZhou
// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("仙人碑", ({ "board" }) );
	set("location", "/d/xingxiu/btyard");
	set("board_id", "baituo_b");
        set("long", "有什么时要是我不在请留我一张post。\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

