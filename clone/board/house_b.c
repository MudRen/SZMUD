//Board//8/01/2001
//by jiuer 
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"住房系统意见簿"NOR,({"board"}));
        set("location", "/p/fystreet/masteroom");
        set("board_id", "board");
        set("long", "你可以在这个留言板上提交对住房系统的建议，\n也可以在这里设计一些新的家具，巫师会尽快充实到游戏中去的。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
