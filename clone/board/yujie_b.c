inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"��ޱ�������Բ�"NOR, ({ "board" }) );
        set("location", "/u/yujie/workroom");
        set("board_id", "yujie_b");
        set("long", "���ǲݶ�Ϊ���׼�������԰�,��ӭ���ǰ������!\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}