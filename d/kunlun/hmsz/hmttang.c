// hmttang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "厅堂");
                  set("long",@long
你来到一个两进厅堂,外边就是红梅山庄大门,东边是一个暖阁.
long);
                 set("exits",([
"east" : __DIR__"luange",
"out" : __DIR__"hmgate",
]));

set("objects",([
                __DIR__"npc/qiaofu" :  1,
                __DIR__"npc/xiaofeng" :  1,
]));
              setup();
              replace_program(ROOM);
}
