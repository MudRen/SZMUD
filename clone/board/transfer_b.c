// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ݴ����������", ({ "board" }) );
set("location", "/d/city/guangchang"); 
        set("board_id", "transfer_b_new");
        set("long", "����һ�����������ʦ�㱨���ݴ���ֵ����԰档\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
