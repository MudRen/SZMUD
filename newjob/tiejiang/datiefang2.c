// CODE BY SCATTER
// V. 1.0
// describing BY SNOWLF

#include <ansi.h>

inherit ROOM;

void create()

{
        set("short", HIC"打铁室"NOR);
        set("long", @LONG
这是一间很普通的打铁室，南面有扇窗，窗下不远，靠西边墙的地方有个打
铁台，有火炉(stove)和风箱，墙角还有一此箱子(box)，想必是装原材料或木炭
及工具之类用的吧。
LONG
        );

	set("exits", ([
                "east" : "/newjob/tiejiang/datiechang.c"
				]));
        set("item_desc", ([
                        "stove": "你摸摸炉边，还有余温，想必是前不必还有人在这里用过它打制东西呢！\n",
                        "box": "你是来打铁的吗？找找看箱子里有没有你用的上的东西吧。\n",
                        "火炉": "你摸摸炉边，还有余温，想必是前不必还有人在这里用过它打制东西呢！\n",
                        "箱子": "你是来打铁的吗？找找看箱子里有没有你用的上的东西吧。\n",
                        ]));     

		set("objects",([
                "/newjob/tiejiang/obj/datietai.c": 1,
		]));

        setup();
}

