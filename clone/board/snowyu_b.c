// Code of ShenZhou
// /clone/snowyu/snowyu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("ѩ���ռǱ�", ({ "board" }) );
        set("location", "/u/snowyu/workroom");
        set("board_id", "snowyu_b");
        set("long", "����ѩ�Ƶ��ռǱ���\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
