//Board//8/01/2001
//by jiuer 
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"地主家的账簿"NOR,({"board"}));
        set("location", "/u/dizhu/workroom");
        set("board_id", "board");
        set("long", "小地主的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
