// Code of ShenZhou
// jiulao3.c 九老洞
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>
string *dir=({"up","left","right"});

int     do_next(string arg);
void create()
{

                                        
        set("short", HIW"华山之巅"NOR);
        set("long", @LONG
你正身处华山之巅，天候骤寒，铅云低压，北风渐紧，接着天空竟飘
下一片片的雪花,渐渐的雪下得一发大了，足底溜滑，道路更是难于辨认，
若是踏一个空，势必掉在万仞深谷中跌得粉身碎骨。你只有小心翼翼的爬
爬(climb)看了。
LONG
        );
        set("outdoors", "huashan");
        set("cost", 5);
       setup();
}
void init()
{
        add_action("do_next","climb");
}
int do_next(string arg)
{
        object me = this_player();
        int cost,dodge;

        dodge = me->query_skill("dodge",1)/20+1;
        cost = 4000/dodge+1;
        cost = random(cost) + 100;
        
        if(me->is_busy())
                return notify_fail("你还在忙着呢。\n");

        me->start_busy(2+random(2));
        
        if (!arg)
        {
                tell_object(me,"你想向哪个方向爬？左(left),右(right)，上(up)。\n"NOR);

                return 1;

        }
        if (me->query("jingli")<500)
        {
                tell_object(me,HIY"你的体力透支，昏了过去。\n"NOR);
                me->add("jingli",-500);
                return 1;
        }
        if (arg == dir[random(3)] )
        {
                message_vision(HIG"$N找到了一个避风之处，准备歇口气再爬。\n"NOR,me);
                me->move("/u/slow/questwg/jueding2");
                me->add("jingli",-cost);
                

        }
        else if (arg == "down")
        {
                message_vision("$N小心翼翼的爬了下去。\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->add("jingli",-cost);
        
        }
        else if (arg=="left" || arg=="right" || arg=="up" )
        {
                tell_object(me,HIR"你费了很大力气爬了过去，却发现爬错了方向，只好退回了原地。\n"NOR,me);
                me->add("jingli",-cost);
                me->move("/u/slow/questwg/jueding1");

        }
        else
        {
                tell_object(me,"这个方向不能爬。\n");
                
        }
        
        
        return 1;
}
