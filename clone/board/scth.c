//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("�һ��ʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/th");
        set("board_id", "scth");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}

