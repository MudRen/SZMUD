// /clone/board/wulin_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��������", ({ "board" }) );
        set("location", "/d/wulin/xiaowu");
        set("board_id", "wulin_b");
        set("poster_level", "(player)");
        set("long", "��������ͬ��������˽�����Բ�����ӭ���Ὠ�顣\n");
        set("intermud", 1);
        setup();
        set("capacity", 400);
        replace_program(BULLETIN_BOARD);
}

