inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name(HIC"阅薇草堂留言簿"NOR, ({ "board" }) );
        set("location", "/u/yujie/workroom");
        set("board_id", "yujie_b");
        set("long", "这是草儿为大家准备的留言板,欢迎大家前来交流!\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}