//Board//8/01/2001
//by jiuer 
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"ס��ϵͳ�����"NOR,({"board"}));
        set("location", "/p/fystreet/masteroom");
        set("board_id", "board");
        set("long", "�������������԰����ύ��ס��ϵͳ�Ľ��飬\nҲ�������������һЩ�µļҾߣ���ʦ�ᾡ���ʵ����Ϸ��ȥ�ġ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
