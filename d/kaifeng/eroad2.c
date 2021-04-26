//Room: /d/kaifeng/eroad2.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以
听到守城官兵的吆喝声。西边是开封大道，那边一派肃静。原来是因
为开封府在那头。南北是一条宽直的大道。
LONG
        );

        set("exits", ([
                "south" : __DIR__"eroad2s",
                "west":__DIR__"eroad1",
                "east":__DIR__"dongmen",
                ]));

       set("objects",([
         "d/city/npc/liumangtou":1,
        ]));

         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}

