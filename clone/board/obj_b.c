//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("��Ʒ�������԰�", ({ "board" }) );
        set("location", "/d/wizard/obj_r");
        set("board_id", "obj_b");
        set("long", "�й���Ʒ������������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}