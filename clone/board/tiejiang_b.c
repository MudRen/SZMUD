inherit BULLETIN_BOARD;

void create()
{
        set_name("��������������԰�", ({ "board" }) );
        set("location", "/newjob/tiejiang/datiechang");
        set("board_id", "tiejiang_b");
        set("long", "����԰����й������Ľ����BUG POST ����" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
