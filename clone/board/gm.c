//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("��Ĺ�ʼǰ�", ({ "board" }) );
        set("location", "/u/scatter/workroom/gm");
        set("board_id", "scgm");
        set("long", "��ڤ�ӵĸ��˱ʼǡ�\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
