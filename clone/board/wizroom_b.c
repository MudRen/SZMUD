// Code of ShenZhou
// /clone/board/wizroom_b.c

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
        set_name(CYN "Ǭ������" NOR, ({ "board" }) );
        set("location", "/d/wizard/wiz_room");
        set("board_id", "wizroom_b");
        set("long", "���ǹ�����ʦר�õ����԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
