//Room: /d/kaifeng/dadao.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
你走在一条青石官道上，这里已经是开封境内了，路上时时可以
看到各色各样的商人来来往往，络驿不绝。路边站了些个衣饰华艳的
女子，其中一个身穿白衣的显得格外秀丽。此去向东即是开封府了。
LONG
        );

        set("exits", ([
                "east" : __DIR__"ximen",
                "west":__DIR__"daqiao",
              ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
