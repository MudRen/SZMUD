inherit BULLETIN_BOARD;

void create()
{
        set_name("�㷢�����鲻����ˣ�������˵������ - ���԰�", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "errorboard");
        set("long", "����㿴�� �㷢�����鲻����ˣ�������˵�������� ������� post �����\n��Ҫ������˵���µĶ���\n-���﷢����\n-ʲô�������\n\n��Ȼ, ����Խ�����Ǿ��޵�Խ��\n\n���лл������ϡ�" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
