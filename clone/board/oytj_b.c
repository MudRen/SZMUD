// Code of ShenZhou
// /clone/board/oytj_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIW "�����ɫ" NOR, ({ "board" }) );
        set("location", "/u/oytj/workroom");
        set("board_id", "oytj_b");
        set("long", "���ǲʺ��������ʦ���������԰�,��ʲô�������Ҳ�����԰ɡ�\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
