//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("���������԰�", ({ "board" }) );
        set("location", "/d/wizard/kungfu_r");
        set("board_id", "scatter_mb");
        set("long", "�йع�������������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}