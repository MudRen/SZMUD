inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"思远阁事件笺"NOR, ({ "board" }) );
        set("location", "/u/felix/workroom");
        set("board_id", "felix_b");
        set("long", "这里记载着思远阁的历史，一幅画，一首诗，一个梦里出现的人。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}