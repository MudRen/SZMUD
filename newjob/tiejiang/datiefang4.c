// CODE BY SCATTER
// V. 1.0
// describing BY SNOWLF

#include <ansi.h>

inherit ROOM;

void create()

{
        set("short", HIC"地下打铁室"NOR);
        set("long", @LONG
这是一间很看起来似乎是很普通的打铁室，位于地下，东南和西南角上各有
一扇气窗，天晴的百天阳光可以从这里照下来，距南墙不远，靠东边的地方有个
打铁台，有火炉(stove)和风箱，墙角还有一此箱子(box)，想必是装原材料或木
炭及工具之类用的吧。
LONG
        );

	set("exits", ([
                "up" : "/newjob/tiejiang/datiechang.c"
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

