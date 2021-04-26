//Created by Zyu on k1-08-13
// road: /d/wuguan/garden.c

inherit ROOM;

void create()
{
        set("short", "武馆花园");
        set("long", @LONG
这里就是武馆的花园了。鲜花在开放，树木在抽枝，鸟儿在歌唱，你
感到自己醉在这一切中了。一条小径从花园外面进来，经过你的足迹，消
失在遮住你视线的树木背后。那儿会是什么呢？
LONG
        );
        set("outdoors", "wuguan");
        set("item_desc", ([
        ]));

        set("objects", ([
                 __DIR__"obj/shizi" : 1,
                 __DIR__"obj/flower1" : 1,
                 __DIR__"obj/flower2" : 1,
                 __DIR__"obj/flower1" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"gardeno",
                "east" : __DIR__"gardeni",
        ]));

        set("cost", 1);
        setup();
}