// /clone/board/gumu_skill_mb.c
// By Scatter

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ĹSKILL������԰�", ({ "board" }) );
set("location", "/u/scatter/workroom"); 
	set("board_id", "gumu_skill_mb");
	set("long", "����԰����йع�ĹSKILL�Ľ��� POST ����" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}
