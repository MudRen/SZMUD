// Code of ShenZhou
inherit ROOM;

void create()
{
        set("short", "故事房入口");
        set("long", @LONG
再往前走就儿童不宜了。门口站了一个小孩笑嘻嘻的看着你
LONG
        );
        set("objects", ([
"/u/lyu/collector" : 1,
        ]));
        set("exits", ([
 "out" : "/d/city/kedian",
]));

        set("cost", 1);
        setup();
}

