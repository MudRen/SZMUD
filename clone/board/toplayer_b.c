// Code of ShenZhou
// /clone/board/toplayer_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("������﹫���", ({ "board" }) );
        set("location", "/d/wizard/news_room");
        set("board_id", "toplayer_b");
        set("long", "����һ�����������˷�������Ϸ���¸��µ����԰塣\n" );
        set("intermud", 1);
        set("poster_level", "(immortal)"); 
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
