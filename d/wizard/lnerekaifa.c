// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", CYN"开发工作室"+NOR);
        set("long", @LONG
这里是天帝与首席开发神仙的主持的会议室，天花板上悬着一盏大吊灯，
照耀明亮。大厅中央放着一张圆型的会议桌，上面摆着几束鲜花，正散发出阵
阵芳香，桌上还放几台笔记本电脑和一本会议记录簿(board)。听说【神州】
的重大事项都是在这里决定的。
LONG
        );
        set("exits", ([ 
             "west" : "/d/wizard/general_r",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
          call_other("/clone/board/lnerekf_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
