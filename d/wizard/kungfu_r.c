// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"功夫技能会议室"+NOR);
        set("long", @LONG
这里是首席功夫技能设计神仙所主持的会议室，四周都是打磨光滑的大石
壁，壁上刻得有图有字，仔细一看，似乎都是各门派的武功招式。南面的墙角
放着一张楠木桌，上面放着一本会议记录簿(board)。据说许多令人神往的武
林神话都是在这里创造出来的。
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
        call_other("/clone/board/kungfu_b", "???");
        call_other("/clone/board/kf_Pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
