// room /d/wulin/fachu.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "罚恶处");
        set("long", @LONG
这里就是罚恶处，罚恶使者通常在这处罚藐视破坏武林同盟的武林败类，地
上到处摆满了各种刑具，墙上还有未干的血迹，空气中弥漫着一股血腥的味道。
LONG
        );

        set("exits", ([
         "west" : __DIR__"zhengqiting",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
