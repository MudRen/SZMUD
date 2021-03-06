 // Code of ShenZhou
// jindian.c 金殿 
// by Fang 8/20/96
// Update By Scatter
// V 1.0

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"金殿"NOR);
        set("long", @LONG
金殿中间供着真武大帝铜像，披发跣足，体态丰满；左右有金童玉女侍立，
虔诚恭敬；水、火二将，威武庄严。殿前供器皆为铜铸。殿宇和殿内铜像、供
桌铆焊一体，构件精确，技巧高超。
LONG
        );
//        set("outdoors", "wudang");

        set("exits", ([
                "north" : __DIR__"zijin",
        ]));
        set("cost", 1);
        setup();
}

  void init()
{
    add_action("lingwu","lingwu");
}

int lingwu()
{
    object me = this_player();
    int rndnmb=random(500);

    if(me->is_busy())
        return notify_fail("你正在忙呢！\n");
    if(me->query("zhenwu/5x"))
        return notify_fail("你已经会啦！\n");
    if(!me->query("zhenwu/6x"))
        return notify_fail("你先找别人学阵吧，根本就看不懂！\n");
        if(!me->query("family")||me->query("family/family_name")!="武当派")
        return 0;
    if(me->query("combat_exp")<100000)
        return notify_fail("你的实战经验不足，现在没法学「真武七截阵」！\n");
      if(me->query_skill("taiji-shengong",1)<100)
        return notify_fail("你的内功心法不够，学「真武七截阵」对你有害无益！\n");
    if(me->query_skill("taoism", 1)<100)
        return notify_fail("你对道学心法还不够了解，不能体会「真武七截阵」的阵意！\n");
    if(me->query("max_neili")<1000)
        return notify_fail("你的内力基础不好，先去打好基础再来领悟吧！\n");
      if(me->query_skill("parry",1)<100)
        return notify_fail("武当绝学是以柔克刚，你连一般招式都招架不住，怎么学「真武七截阵」！\n");
    if(me->query("max_jingli")<1000)
        return notify_fail("领悟「真武七截阵」不是一朝一夕的事，把精力练高一点再来领悟吧！\n");
        if ( me->query("jingli") < 2000 )
                {
                                command("say 练习「真武七截阵」不是一天两天的事，我看以你现在的体力还不适合练。");
                                return 1;
                }
                if ( me->query("neili") < 2000)
                {
                        command("say 练习「真武七截阵」不是一天两天的事，你现在的内力还不适合练。");
                        return 1;
                }


    
                message_vision(NOR"$N反复琢磨着阵法要诀。\n"NOR, me);

        if(rndnmb<460)
        {
                me->add("jing",-10);
                me->start_busy(10);
                                me->unconcious();
                                message_vision(HIR"$N突然一阵晕眩，眼前的一切似乎都在打转。．\n"NOR, me);
        return 1;
        }

    me->set("zhenwu/5x",1);
    message_vision(HIC"$N心演阵法，灵动如长蛇，凝重如乌龟，对阵法大有领悟！\n"NOR, me);
    return 1;
}

