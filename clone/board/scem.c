inherit BULLETIN_BOARD;

void create()
{
        set_name("���ұʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/em");
        set("board_id", "scem");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

