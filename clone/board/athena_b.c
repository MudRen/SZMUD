// Code of ShenZhou
// /clone/board/athena_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(MAG "������¥" NOR, ({ "board" }) );
        set("location", "/u/athena/workroom");
        set("board_id", "athena_b");
        set("long", "�����Չ�ܰ��������ʦ���������԰塣\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
