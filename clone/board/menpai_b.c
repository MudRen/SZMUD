// Code of ShenZhou
// /clone/board/menpai_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���������԰�", ({ "board" }) );
        set("location", "/d/wizard/smiling_room");
        set("board_id", "progress_b");
        set("long", "����һ������������ʦ�ǽ��������԰塣\n" );
        set("wizard_only", 1);
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
