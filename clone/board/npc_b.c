// Code of ShenZhou
// /clone/board/guide_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("非玩家人物讨论板",({"board"}));
	set("location", "/d/wizard/npc_r");
	set("board_id", "npc_b");
	set("long", "这是供大家讨论非玩家人物相关问题的留言板.\n");
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

