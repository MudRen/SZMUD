inherit BULLETIN_BOARD;

void create()
{
        set_name("�������Լ�¼", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "feizeibskill");
        set("long", "����һ������ʦ���Ժ�ı��档\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
