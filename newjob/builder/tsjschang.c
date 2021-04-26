//room: /newjob/builder/tszschang.c 泰山巨石场
//Lara 2001/12/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "巨石场");
        set("long", @LONG
穿过神秘的小树林，眼前豁然开朗。眼前出现一片壮观的景象，一座
白色的山峰拔地而起，山上寸草不生，整座山犹如一块巨大的玉石。山下
有一条不太起眼的小河，小河一直流向山腹中，流水的回声震耳欲聋，看
来是一条很大的地下暗流。
LONG
        );

        set("exits", ([        
        "out" : __DIR__"tsshiwu",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
