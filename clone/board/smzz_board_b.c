//Cracked by smzz
// /u/smzz/board.c
inherit BULLETIN_BOARD;


void create()
{
set_name("����������԰�", ({ "board" }) );
set("location", "/u/smzz/workroom");
set("board_id", "towiz_b");
set("long", "�ҹ�ˮ�ߴ���ʮ�˲������\n" );
setup();
set("capacity", 200);
replace_program(BULLETIN_BOARD);
}

