//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("ѩɽ�ʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/xs");
        set("board_id", "scxs");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

