// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
             set_name(HIG+"宠"+HIM+"辱"+HIC+"不"+HIR+"惊"+NOR, ({ "board" }) );
            set("location", "/u/hap/workroom");
                 set("board_id", "hap_b"); 
        set("long", "这是管理巫师专用的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
