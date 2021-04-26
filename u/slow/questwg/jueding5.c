// Code of ShenZhou
// jiulao3.c 九老洞
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>
string *dir=({"up","left","right"});

int     do_next(string arg);
int     do_cry();
void create()
{

                                        
        set("short", HIW"华山绝顶"NOR);
        set("long", @LONG
这是一处人迹罕至的山峰绝顶，足底溜滑，山势险峻，若是一脚踏空，势必
掉在万仞深谷中跌得粉身碎骨,相传华山论剑就在此处。
LONG
        );

        set("objects", ([
                "/u/slow/questwg/hong2" : 1,
        ]));

        set("outdoors", "huashan");
        set("cost", 5);
       setup();
}
void init()
{
        add_action("do_next","climb");
        add_action("do_cry","cry");
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
                tell_object(me,"你想向哪个方向爬?\n"NOR);

                return 1;

        }
        if (me->query("jingli")<500)
        {
                tell_object(me,HIY"你的体力透支，昏了过去。\n"NOR);
                me->add("jingli",-500);
                return 1;
        }
        
        if (arg == "down")
        {
                message_vision("$N小心翼翼的爬了下去。\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->add("jingli",-cost);
        
        }
        else
        {
                tell_object(me,"这个方向不能爬。\n");
                
        }
        
        
        return 1;
}

int do_cry()
{

        command("cry");
        

}
