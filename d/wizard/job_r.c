// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"工作系统会议室"+NOR);
        set("long",
 "这里是首席工作系统设计神仙所主持的会议室，对着入口处的墙壁上挂有一\n"
+"联，写在木牌上，"+HIW+"「朝宜调琴，暮宜鼓瑟；旧雨适至，新雨初来。」"+NOR+"字体飘逸出\n"
+"尘，苍劲有力。屋子正中摆了圆桌方椅，在两盏挂垂下来的宫灯映照下，除桌椅\n"
+"外只有几有件必需的家俱，均为酸枝木所制，气派古雅高贵。\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/job_board", "???");
        call_other("/clone/board/job_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
