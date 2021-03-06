// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"大厅"NOR);
        set ("long", "这里是大厅，厅上正中挂着一块大横扁，上书"HIW"【神州】"NOR"。厅内摆
的全是雕镂精细的家具，中置叁屏云石大卧椅，东西对称各两对云石圆屏
靠椅，正面的墙壁上挂着一幅地图（map）。北边是书馆，西边是杂货店，
东边是武器库。你可以在这里熟悉一下基本的命令。
");
        set("item_desc", ([
                "map" : HIG+"

                  ************************
	              欢迎光临【神州】
                  ************************\n"+NOR+"

                    睡房 ← 书馆
                             ↑ 
                    杂货店←大厅→武器库\n\n",
        ]));

	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"welcome3",
		"west" : __DIR__"welcome4",
		"north" : __DIR__"welcome5",
		"down" :"/d/city/kedian",
		]));

	set("valid_startroom", "1");
	set("no_fight", 1);

setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="enter" ) return 1;

	if( dir=="down" ) {
		me->delete("newbie", "yes");
	}
	return ::valid_leave(me, dir);
}
