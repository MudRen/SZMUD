// Code of ShenZhou
// /clone/board/transfer_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���תվ���԰�", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "transfer_b");
        set("long", "����һ��������ύ��ס�����ݡ���������԰塣\n" );
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
