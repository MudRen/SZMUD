//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����ʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/tiejiang");
        set("board_id", "sctiejiang");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

