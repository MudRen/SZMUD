// Code of ShenZhou
// /clone/board/lara_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("̽Ĺ�ּ�", ({ "board" }) );
        set("location", "/u/lara/workroom");
        set("board_id", "lara_b");
        set("poster_level", "(apprentice)");
        set("long", "���ǹ���ʦ����ʾ�õģ���Ҳ���������\n");
        set("intermud", 1);
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}

