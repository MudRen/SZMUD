//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
          set_name("�������԰�", ({ "board" }) );
          set("location", "/d/wizard/lneremenpai");
        set("poster_level", "(wizard)");
        set("board_id", "devide_b");
        set("long", "�����ϯ�������������ֹ���������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
