//Cracked by smzz
// /u/smzz/board.c
inherit BULLETIN_BOARD;
#include <ansi.h>


void create()
{
set_name(RED "神州外传谱" NOR, ({ "board" }) );
set("location", "/u/smzz/workroom");
set("board_id", "smzz_b");
set("long", HIW"乱灌水者打入十八层地狱！这只是完家与巫师之间的交流空间NOR\n" );
setup();
set("capacity", 200);
replace_program(BULLETIN_BOARD);
}

