//Board//8/01/2001
//by jiuer 

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIW"*** "HIG"天帝重要信息公告板 "HIW"*** "NOR, ({ "board" }) );
        set("location", "/d/wizard/meeting_room");
        set("poster_level", "(admin)");
        set("board_id", "admin_b");
        set("long", "天帝发布本站重要公告的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}