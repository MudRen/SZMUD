//Room: /d/kaifeng/wroad1.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "开封大道");
        set("long", @LONG
这里是开封大道，它横贯整个开封城。向东就可以到开封府了。
平头百姓少了，路上大多是有头有脸的爷们。几个官兵顶盔贯甲打量
着过往行人。
LONG
        );

        set("exits", ([
                "west" : __DIR__"wroad2",
                "east":__DIR__"guangchang",
                
        ]));

        set("objects",([
                 __DIR__"npc/bing":1,
          ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}

