// /clone/board/jiulu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ž�����ī��", ({ "board" }) );
        set("location", "/d/wulin/jiulu");
        set("board_id", "jiulu_b");
        set("long", "��ӭ�ƺ���ī��\n" );
        setup();
        set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}

