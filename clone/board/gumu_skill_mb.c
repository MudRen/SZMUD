// /clone/board/gumu_skill_mb.c
// By Scatter

inherit BULLETIN_BOARD;

void create()
{
	set_name("古墓SKILL意见留言板", ({ "board" }) );
set("location", "/u/scatter/workroom"); 
	set("board_id", "gumu_skill_mb");
	set("long", "你可以把你有关古墓SKILL的建议 POST 上来" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}
