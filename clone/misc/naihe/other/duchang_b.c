//  亦是抄袭而来，但终究看不出哪里设定了版主ID……  //  /clone/board/duchang_b.c
//  by naihe  2002-04-09

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("赌场留言版", ({ "board" }) );
        set("location", "/u/naihe/dc_dating");
        set("board_id", "duchang_b");                                
        set("long","这是赌场的留言版，玩家们可以在这里交流心得、炫耀战绩、询问问题等。\n"
);
        setup();
        set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}
