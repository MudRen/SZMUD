// Code of ShenZhou
inherit BULLETIN_BOARD;

void create()
{
        set_name("������ʾ��", ({ "board" }) );
        set("location", "/d/dali/wangfu1");
        set("board_id", "dali_b");
        set("long", "һ�����ľ�����ӡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

