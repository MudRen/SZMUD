//Cracked by smzz
// /u/smzz/board.c
inherit BULLETIN_BOARD;


void create()
{
set_name("最高领袖留言板", ({ "board" }) );
set("location", "/u/smzz/workroom");
set("board_id", "towiz_b");
set("long", "乱灌水者打入十八层地狱！\n" );
setup();
set("capacity", 200);
replace_program(BULLETIN_BOARD);
}

