// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("���ݴ����������", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "transfer_b");
        set("long", "����һ�����������ʦ�������ֵĵط���\n" );
        set("poster_level", "(apprentice)");
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
