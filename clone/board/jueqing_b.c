// /clone/board/jueqing_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰�", ({ "board" }) );
        set("location", "/d/jueqing/shiwu");
        set("board_id", "jueqing_b");
        set("long", "һ�����ܵ����黨�Ĵ�ľ���ӡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

