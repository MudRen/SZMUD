
// Code of ShenZhou
// Room: yuzf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
        set("short", "玉柱峰");
        set("long", @LONG
这里是长白主峰之一，又名青石峰，东北距白云峰仅里许的路程。此峰
高耸，象一根擎天的玉柱，顶天立地，高不可攀，可谓白云峰之辅弼。此峰
山路崎岖，且冰多路滑，为入山的最后一道屏障。
LONG    );

        set("exits", ([ 
              "northwest" : __DIR__"lumf",
              "eastdown" : __DIR__"tianchi",
              "northeast" : __DIR__"baiyf",
              "southeast" : __DIR__"tiyf",
        ]));

        set("objects",([
                __DIR__"npc/tian" : 1,
        ]));
        
        set("fjing", 1);
        set("outdoors", "changbai");

        set("count", random(3)+1);

        setup();
}
int valid_leave(object me, string dir)
{
    if (dir=="southdown") {
        say (me->name()+"顺着南面的小路走了下来，杂草又把路掩盖起来。\n");
        me->set_temp("new_valid_dest", "/d/changbai/fen");
	delete("exits/southdown");
               return 1;
    }
    return ::valid_leave(me, dir);
}
