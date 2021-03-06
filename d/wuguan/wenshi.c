//Created by Sleep on k1-08-11
//Modified by Zyu on k1-08-11
// road: /d/wuguan/wenshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "温室");
        set("long", @LONG
这是一间密闭的房间。气温相当合适，周围有无数的鲜花簇拥着你，
你真想摘几朵带在头上，可一个声音一直在告诉你什么(voice),你越走越
深，最后终于醉倒在花海中了。
LONG
        );
        set("outdoors", "wuguan");
        set("item_desc", ([
                "voice" : "声音可不能看！得听(listen)。\n"
        ]));

        set("exits", ([
                "northeast" : __DIR__"gardeni",
        ]));

	set("objects", ([
		__DIR__"npc/huajiang" : 1,
	]));

        set("cost", 1);
        setup();
}

void init()
{
	add_action("do_listen", "listen");
}

int do_listen(string arg)
{
	object me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg!="voice" ) return notify_fail("在这儿，你只能听声音(voice)！\n");

	message_vision(CYN"空洞的声音说道：快干活，别偷懒。\n"NOR, me);

	return 1;
}