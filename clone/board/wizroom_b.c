// Code of ShenZhou
// /clone/board/wizroom_b.c

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
        set_name(CYN "乾坤万象" NOR, ({ "board" }) );
        set("location", "/d/wizard/wiz_room");
        set("board_id", "wizroom_b");
        set("long", "这是管理巫师专用的留言板。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
