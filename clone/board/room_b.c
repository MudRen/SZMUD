//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ͼ�������԰�", ({ "board" }) );
        set("location", "/d/wizard/room_r");
        set("board_id", "room_b");
        set("long", "�йص�ͼ������������԰塣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}