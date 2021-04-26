// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"地图地理会议室"+NOR);
        set("long",
  "这是是首席地图地理设计神仙所主持的会议室，左右两边墙上，各挂有十多\n"
+"把造型各异的宝刀，向门的另一端靠墙处放有＊方像石笋般形状，黝黑光润，高\n"
+"及人身的巨石，为添加另一种难以形容的意味。中间的桌子上放着一块"+HIW+"【地图地\n"
+"理留言板 】"+NOR+"(board)，据说是神仙们在这里交流有关地图、房间、机关的设计和\n"
+"编程方面的知识时留下的。\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/room_b", "???");
        call_other("/clone/board/room_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
