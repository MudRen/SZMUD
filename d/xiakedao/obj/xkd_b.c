//Cracked by Roath
inherit BULLETIN_BOARD;

void create()
{
        set_name("���͵���ʾ��", ({ "board" }) );
        set("location", "/d/xiakedao/dadong");
        set("board_id", "xkd_b");
        set("long", "һ�����ľ�����ӡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

