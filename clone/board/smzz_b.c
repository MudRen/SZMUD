//Cracked by smzz
// /u/smzz/board.c
inherit BULLETIN_BOARD;
#include <ansi.h>


void create()
{
set_name(RED "�����⴫��" NOR, ({ "board" }) );
set("location", "/u/smzz/workroom");
set("board_id", "smzz_b");
set("long", HIW"�ҹ�ˮ�ߴ���ʮ�˲��������ֻ���������ʦ֮��Ľ����ռ�NOR\n" );
setup();
set("capacity", 200);
replace_program(BULLETIN_BOARD);
}

