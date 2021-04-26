// sleeproom.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIC"睡房"NOR);
        set ("long", "这里是一间面积很小的休息室，房里摆着两张不大的木床，睡一两人
而已，你可以键入“sleep”睡觉。祝你休息好。
");

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"welcome5",
                ]));

        set("objects", ([
                "/d/welcome/npc/yahuan" : 1,
                ]));

        set("valid_startroom", "1");
        set("no_fight", 1);
        set("sleep_room", 1);
        setup();
}
