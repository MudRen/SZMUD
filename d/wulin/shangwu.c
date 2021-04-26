// room /d/taishan/shangwu.c
//updated by Lara 2001/10/14
inherit ROOM;

void create()
{
        set("short", "尚武轩");
        set("long", @LONG
你来到一座威武的建筑面前，只见“尚武轩”三个大字在阳光下熠熠
生辉。这三个字写的好生遒劲，你看着那铁划银钩不禁伸手模仿起来，突
然间你感觉一股豪气充塞胸臆。西边传来一阵令人食指大动的香气，那是
著名的饕餮楼，东面是著名的英雄大会广场，往北就到武林同盟正殿的殿
门了。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shanlu",
                "north" : __DIR__"dianmen",
         "east" : __DIR__"guangchang",
         "west" : __DIR__"taotielou",
]));

        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "taishan");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}











