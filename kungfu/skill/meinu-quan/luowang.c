// Code by Scatter
// 天罗地网势
// luowan.c
// V. 1.14

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
  object ob;
  string msg;
    int intBT;

    if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("天罗地网势只能对战斗中的对手使用。\n");

//      weapon = me->query_temp("weapon");
//      weapon2 = target->query_temp("weapon");

        if( !living(target) )
                return notify_fail("你现在没有必要使用天罗地网势。\n");

        if( me->query_temp("yield") )
                return notify_fail("你不出手，如何使出天罗地网势？\n");

        if (target->is_busy())
                return notify_fail("对手正在忙着呢。\n");


//      if( me->query_temp("luowang/"+target->name()) )
//              return notify_fail("你已经用天罗地网势牵制住"+ target->name() +"了，放胆攻击吧。\n");

        if( (int)me->query_skill("meinu-quan", 1) < 100 )
                return notify_fail("你的美女拳法不够娴熟，使不出天罗地网势。\n");

        if( (int)me->query_skill("yunu-xinjing", 1) < 120 )
                return notify_fail("你的玉女心经修为不够，使不出天罗地网势。\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你现在的内力不足以使出天罗地网势！\n");

        if( me->query("jingli") <= 100 )
                return notify_fail("你现在的体力不足以使出天罗地网势！\n");

        if( me->query_skill_mapped("parry") != "meinu-quan" )
                return notify_fail("你的招架并非美女拳, 无法使出天罗地网势。\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("你所用的内功不对, 无法使出天罗地网势！\n");

        me->add("neili", -50);
        me->add("jingli", -50);

    msg = "\n"+HIW"\n只见$N双臂飞舞，发掌奇快，两只手掌宛似化成了千手千掌笼罩在$n的身前，一招一式清清楚楚自成段落。\n"NOR;

// Perform Check   N > 2n
        if( random(me->query("combat_exp")) > random(target->query("combat_exp")) * 2)
        {
                msg += HIC"只见$N突然之间好象多了几只手，没等$n明白的时候已经被$N掌风罩住了全身，想动也动不了了！\n"NOR;
        intBT = (int)me->query_skill("meinu-quan",1) / 10;
                target->start_busy(intBT);
                me->add_temp("luowang/"+target->name(), 1);
//              call_out("luowang_checking", 1, me, target);
        }
// Perform Check  N > n
        else if( random(me->query("combat_exp")) * 2 > random(target->query("combat_exp")))
        {
                msg += HIC"$n见$N突然出掌奇的快，让人匪夷所思，脚下一缓整个身子都被掌影包围了！\n"NOR;
        intBT = (int)me->query_skill("meinu-quan",1) / 25;
                target->start_busy(intBT);
                me->add_temp("luowang/"+target->name(), 1);
//              call_out("luowang_checking", 1, me, target);
        }
    else
    {
        message_vision(HIB"\n$n突然发现$N身形突变，感觉不对立时向后纵身才没被拦在掌影之中！\n"NOR, me, target);
        intBT = random(4);
        me->start_busy(intBT);
    }
    message_vision(msg+"\n", me, target);
    return 1;
}


/*
void luowang_checking(object me, object target)
{
        object weapon = me->query_temp("weapon");

        if( !me ) return;

        if( !me->is_fighting() || !living(me) || me->is_ghost() )
        {
                me->delete_temp("chan");
                return;
        }
        else if( !objectp(weapon) || weapon->query("skill_type") != "cuff" )
        {
                me->delete_temp("chan");
                me->start_busy(1);
                message_vision(CYN "\n$N手中有武器，拳意顿失！\n"NOR, me);
                return;
        }

        else if( me->query_skill_mapped("cuff") != "meinu-quan"
        || me->query_skill_mapped("parry") != "meinu-quan" )
        {
                me->delete_temp("luowang");
                me->start_busy(2);
                message_vision(CYN "WEAPON FAIL MESSAGE"NOR, me);
                return;
        }
        else if( me->query("neili") <= 100 )
        {
                me->delete_temp("luowang");
                me->start_busy(1);
                message_vision(CYN "\n$N突然发现你原来是真气不足了！\n"NOR,me);
                return;
        }           

        call_out("luowang_checking", 1, me, target);
}

*/
