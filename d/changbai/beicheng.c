// Code of ShenZhou
// Room: beicheng.c

inherit ROOM;

void create()
{
	set("short", "北城");
	set("long", @LONG
这里是用黄土铺就的街道，街上的行人不多，看起来很冷清。偶尔有几
个身着异域服饰的行人走过，看起来是满族，鲜族的居民。西面有一条幽深
的小巷，不知通向何处。
LONG
	);

	set("exits", ([
		"south" : __DIR__"jishi",
                "west" : __DIR__"xiaoxiang",
	]));

        set("objects",([
        //        __DIR__"npc/juren2" : 1,
        //        __DIR__"npc/juren3" : 1,
                 __DIR__"npc/xiucai" : 1,
        ]));

        set("outdoors", "chanbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

