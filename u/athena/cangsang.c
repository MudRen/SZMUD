// Room：/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "江湖沧桑");
        set("long", @LONG
一间十分安静的展览馆，陈列着一本本或厚或薄的书。有的纸质已经发黄，有
的看起来还很新。江湖的恩怨情仇、血雨腥风在这里都成为书中的故事，嬉笑怒骂
任由后人评说。
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        setup();
}
