// Room: /d/chengdu/xidajie1.c
// By Jpei

inherit ROOM;

void create()
{
		set("short", "蜀都大道");
        set("long", @LONG
这里是蜀都大道，它横贯整个锦官城。向东就可以到提督府了。
平头百姓少了，路上大多是有头有脸的爷们。几个官兵顶盔贯甲打量
着过往行人。
LONG );
        set("outdoors", "chengdu");
        set("exits", ([
            "west"  : __DIR__"xidajie2",
            "east"  : __DIR__"center",
        ]));
        set("objects", ([
            "/d/city/npc/bing" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

