// Code of ShenZhou
// /clone/board/futou_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ͷ�����԰�", ({ "board" }) );
        set("location", "/d/city/ft_datang");
        set("board_id", "futou_b");
        set("long", "����һ������ͷ����ڽ��������԰塣\n" );
        setup();
        set("capacity", 60);
        replace_program(BULLETIN_BOARD);
}
