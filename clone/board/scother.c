inherit BULLETIN_BOARD;

void create()
{
        set_name("����ʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/other");
        set("board_id", "scother");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

