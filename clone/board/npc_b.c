// Code of ShenZhou
// /clone/board/guide_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������������۰�",({"board"}));
	set("location", "/d/wizard/npc_r");
	set("board_id", "npc_b");
	set("long", "���ǹ�������۷�������������������԰�.\n");
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

