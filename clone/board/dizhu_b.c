//Board//8/01/2001
//by jiuer 
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"�����ҵ��˲�"NOR,({"board"}));
        set("location", "/u/dizhu/workroom");
        set("board_id", "board");
        set("long", "С���������԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
