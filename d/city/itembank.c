// 物品银行
// /d/city/itembank.c
// Code by Scatter
// 2001/10/24
// V. 1.0
// Lara 2001/12/05
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"物品寄放处"NOR);
set("long", @LONG
这里是铁匠放物品用的房间。房中分别摆放了大小不同的铁架
和木箱。木箱是上了锁，里面好像放了一些贵重物品似的。你常
见到一个人在铁架之间走来走去，很小心的看管铁架上的物品，
听说他是铁匠请回来的看守物品的仆人。
LONG
        );
set("objects", ([ __DIR__"npc/wanzitian.c" : 1,   ]) );

 set("exits", ([
                "west" :__DIR__"qianzhuang.c",
               "southwest" : __DIR__"dongdajie3",
        ]));

            set("valid_startroom", 1);
            set("day_shop", 1); 
        set("no_fight", "1");
        set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
