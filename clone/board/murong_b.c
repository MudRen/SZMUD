// Code of ShenZhou
inherit BULLETIN_BOARD;

void create()
 {        set_name("������������", ({ "board" }) );
        set("location", "/d/murong/qing4");
        set("board_id", "murong_b");
        set("long", "һ�������õİ��ӡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}