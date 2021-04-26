// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"测试调查会议室"+NOR);
        set("long", @LONG
这里是测试调查统筹神仙所主持的会议室，墙的四周摆放着几张桌子，桌
上的电脑正在吱吱作响地工作着，不过似乎有点不胜负荷，墙壁的四周散落着
许多元秘的的瓶子，听说都是通宵达旦的开会、测试程序的神仙们留下来的。
LONG
        );
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        "/clone/board/test_pro"->foo();
        call_other("/clone/board/test_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
