inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"˼Զ���¼���"NOR, ({ "board" }) );
        set("location", "/u/felix/workroom");
        set("board_id", "felix_b");
        set("long", "���������˼Զ�����ʷ��һ������һ��ʫ��һ��������ֵ��ˡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}