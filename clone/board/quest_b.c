//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("����������԰�", ({ "board" }) );
        set("location", "/d/wizard/quest_r");
        set("board_id", "quest_b");
        set("long", "�й����������������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}