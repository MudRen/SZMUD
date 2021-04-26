// Craked by shenzhou
// Room: /d/sanbuguan/road1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", 
"你走在一条笔直的青石大道上。东面通向江南第一重镇扬州城，道
上人渐渐多起来，远远的你已经能看见城门上刻着的两个大字"+HIW"【西门】"NOR+"。\n"
        );
        set("exits", ([
			"east" : "/d/city/ximen",
			"west" : __DIR__"road2",
			]));

		set("no_clean_up", 0);
		set("outdoors", "sanbuguan");

		set("cost", 1);
		setup();
		replace_program(ROOM);
}

