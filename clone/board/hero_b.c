// /clone/board/hero_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ӣ�����԰�", ({ "board" }) );
 set("location","/d/wulin/guangchang");
	set("board_id", "hero_b");
	set("long", "����һ��̩ɽӢ�����԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

