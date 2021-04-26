//Room: /d/kaifeng/sroad2e.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
你走在南大街上，踩着坚实的青石板地面。这里显得热闹多了。
东北方向是东大街，往西一直走都是南大街。东南方向传来阵阵喧闹，
那里有个客店。
LONG
        );

        set("exits", ([
                "west" : __DIR__"sroad2",
                "southeast":__DIR__"kezhan",
                "northeast":__DIR__"eroad2s",
                ]));
         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
