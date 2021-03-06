// fufengshan.c (kunlun)

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_climb();

void create()
{
		  set("short", "扶峰山");
		  set("long", @LONG
扶峰山极高且十分陡峭，山腰以上尽没入茫茫云海，峰顶终年积雪，山腰
以下却是郁郁苍苍，林木茂密，花团锦簇，春意烂漫
LONG
		  );
		  set("outdoors", "kunlun");

		  set("exits", ([
					 "enter" : __DIR__"houyuan.c",
					 "northeast" : __DIR__"bainiushan.c",
                                         "up" : __DIR__"sanshengao.c",
		  ]));


		  set("no_clean_up",0);
create_door("enter", "小门", "out", DOOR_CLOSED);
                  
                  set("cost", 3);
                  setup();
}

/*
int valid_leave(object me, string dir)
{
        
        if( random((int)me->query_skill("dodge")) <= 30) 
        {
                me->receive_damage("qi", 50, "从山上滚了下来摔死了");
                me->receive_wound("qi",  50, "从山上滚了下来摔死了");
                message_vision(HIR"$N一不小心脚下踏了个空，... 啊...！\n"NOR, me);
                me->move(__DIR__"shanlin1");
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        return notify_fail(HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
        }
        return ::valid_leave(me, dir);
}

*/
