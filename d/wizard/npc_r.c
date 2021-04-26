// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"非玩家人物会议室"+NOR);
        set("long", @LONG
这里是非玩家人物设计神仙所主持的会议室，刚装修过的四周墙壁上挂着几
盏壁灯，屋子正中央摆着一张会议桌，桌上陈列着许多泥塑作品，人物、动物样
样俱全，众多泥人的诸式妙样，似乎来自某位绝世高人的设计，有意无意间把关
於生命的秘密展现在泥人的千姿百态中。
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
        call_other("/clone/board/npc_b", "???");
        call_other("/clone/board/npc_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
