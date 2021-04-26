// Room：/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "风云人物");
        set("long", @LONG
这里是神州风云人物的纪念馆。“江山代有才人出，各领风骚数百年”，苍茫
神州大地，万千风云变幻，那些叱咤江湖的人物，现在都化为一幅幅画像挂在墙壁
上，或工笔，或写意，沉寂无声地看着这个世界。
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        setup();
}

