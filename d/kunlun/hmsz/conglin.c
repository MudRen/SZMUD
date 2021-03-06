// conglin.c (kunlun)

#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "雪地丛林");
                  set("long",@long
你身在一座雪岭的丛林之内。只见一望无际的雪地中留着自己长长的一行足印。
前面是一处悬崖(cliff),对面山坡上七八条大灰狼仰起了头，向着你张牙舞爪的嗥叫，显
是想要食之果腹，下面是一条深不见底的万丈峡谷.
long);
                 set("exits",([
"southdown" : __DIR__"shanpo",
]));


set("cost", 5);
set("outdoors", "kunlun");
setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("你要跟哪儿爬？\n");

        if (me->query_busy())
                return notify_fail("你正忙着呢。\n");

         if( arg=="cliff")
        {
        message_vision("$N看悬崖上的松树,眼睛一闭往数上跳了下去。\n", me);
        me->start_busy(5);

        if (random(me->query_skill("dodge")) < 50){
        remove_call_out("drop_down");
        call_out("drop_down", 5, me);
        return 1;
        }
        
        message("vision", me->name()+"一会儿便消失在山谷雾气里了。\n", environment(me), ({me}) );
        remove_call_out("climb_up");
        call_out("climb_up", 5, me);
        return 1;
        }
}
void drop_down(object me)
{
        tell_object(me, "突然你偏离了方向，直往下坠落。\n");
        message("vision", me->name() + "突然脚一踏空，从山谷上掉了小来。\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 500, "从峭壁上掉了下来摔死了");
        me->receive_wound("qi",  500, "从峭壁上了下来摔死了");
}
void climb_up(object me)
{
        tell_object(me, "你深吸一口气纵身跳了下去，看准方向，落在了松树上。\n");
        me->add("jingli", -100);
        me->move(__DIR__"songshu");
        message("vision", me->name() + "突然从上面掉了下来。\n",
                             environment(me), ({me}) );
}

