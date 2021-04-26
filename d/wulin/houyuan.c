// room /d/wulin/houyuan.c
//updated by Lara 2001/10/17
#include <ansi.h>
inherit ROOM;

void create()
{   
   set("short", "后院");
   set("long", @LONG
这是一个不大的院子，布置看似随便，其实别具匠心。春天可以在这
赏花，夏天可以在这纳凉，秋天可以在这采菊，冬天可以在这踏雪。一走
进这个院子你就觉得心情平和，浑忘了武林中的纷争。
LONG   );

    set("exits", ([
		"north" : __DIR__"lvzhulin",
                "south" : __DIR__"dating",
    ]));
    
    setup();
}
void init()
{
    object me;
    me=this_player();
    if (!interactive(me)) return;
    me->delete_temp("houyuan");
    return;
}
