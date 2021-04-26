// Room：/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "神州巨变");
        set("long", @LONG
这里记录开天辟地以来神州的重大改变。馆内灯光明亮，一尘不染，一本本丝
绢小册子整齐地放在桌子上，任人取阅。
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "west" : __DIR__"dating",
        ]));
        setup();
}
