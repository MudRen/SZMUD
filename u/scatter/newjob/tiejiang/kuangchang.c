//code of 神州

#include <ansi.h>

inherit ROOM;

void create()

{
        set("short", HIC"矿场"NOR);
        set("long", @LONG
这里是一个人工开采的地下矿场。矿场里面又湿又脏，四周的墙壁和地面都
是黑色一片，给人一种不舒服的感觉。在矿场的中央放这一盏大油灯，这是方便
工人在采矿时来照明。当入夜没人的时候，你会听到水珠掉在地上时发出“滴答”
“滴答”的声音。
LONG
        );

        set("possearch", 1);
        set("exits", ([ 
              "out":"/newjob/tiejiang/gate1",
                      ])); 
        setup();
}
