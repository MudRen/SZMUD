// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
              set_name(HIW "说长道短" NOR, ({ "board" }) );
             set("location", "/u/fanren/workroom");
                 set("board_id", "fanren_b"); 
        set("long", "这是管理巫师专用的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
