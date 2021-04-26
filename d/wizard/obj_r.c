// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"物品道具会议室"+NOR);
        set("long", @LONG
这里是首席物品道具设计神仙所主持的会议室，北边的墙角放着两个樟木
大箱和一张长几，长几上摆放了十个精巧的木盒子。四边墙壁则挂着七、八种
形状古怪似是兵器一类的东西。屋子的中间放着一张会议桌，桌上还放着几张
面具和一本会议记录簿(board)。
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
        call_other("/clone/board/obj_b", "???");
        call_other("/clone/board/obj_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
