// Code of ShenZhou

// /clone/board/beijing_b.c

inherit BULLETIN_BOARD;

void create()
{
    set_name("���԰�", ({ "board" }) );
    set("location", "/d/beijing/kedian");
    set("board_id", "beijing_b");
    set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
    setup();
    set("capacity", 200);
    replace_program(BULLETIN_BOARD);
}
