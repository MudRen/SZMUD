// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", HIW"情节谜题会议室"+NOR);
        set("long",
 "这里是首席迷题创作神仙所主持的会议室，刚一进门，只见烟雾弥漫，不\n"
+"但有抽烟管喷出的烟气，还有放在屋角几上檀香炉腾升的烟香，合成一种充盈\n"
+"於厅内的怪味，屋子中间的会议桌上放着一个盒子，盒面雕刻出"+BLU+"【机关学】"+NOR+"叁\n"
+"个大字。据说里面载有关於宇宙千古以来的秘密。\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/quest_b", "???");
        call_other("/clone/board/qst_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
