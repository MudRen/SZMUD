// Code of ShenZhou
// /u/taiyang/board_A.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ݴ����������", ({ "board" }) )
        set("location", "/d/wizard/guest_room");
        set("board_id", "towiz_b")
        set("long", "����һ�����������ʦ�������ݴ���ֵĵط�!��\n" )
        setup();
        set("capacity", 600);
        replace_program(BULLETIN_BOARD);
}
