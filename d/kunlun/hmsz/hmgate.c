// hmgate.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "大门");
                  set("long",@long
面前是一座大庄院,门楼甚是高大,朱漆大门上茶杯大小的铜钉闪闪发光，门顶
匾额写着“红梅山庄”四个金漆大字，门口站着两个家丁,斜着三角眼，恶狠狠
的瞪着你。
long);
                 set("exits",([
"west" : __DIR__"shanao1",
"enter" : __DIR__"hmttang",
]));

set("objects",([
                __DIR__"npc/jiading" :  2,
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
