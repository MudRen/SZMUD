//Cracked by shenzhou
// Room: /baituo/tuopeng.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"骆驼棚"NOR);
        set("long", @LONG
这是白驼山南面的骆驼棚，棚边整齐地摆放着些大梱的干草。你可以
将骑回来的骆驼在这里喂饱饮足，再洗刷得干乾净净。棚外有一口涝坝井
，你可以打水饮骆驼（yin camel）。
LONG
        );

        set("objects", ([
			__DIR__"npc/tu" : 1,            
			"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
			"north" : __DIR__"btgate",
        ]));

        set("resource/water",1);
        set("outdoors", "baituo");
        set("cost",1);
        setup();
}
