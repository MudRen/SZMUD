// kunlun 天山雪飘

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl,damage;
        string msg;
            lvl=(int)me->query_skill("kunlun-zhang", 1)+(int)me->query_skill("mantian-huayu", 1)+ (int)me->query_skill("taxue-wuhen", 1);
       damage = (int)me->query_skill("kunlun-zhang", 1)+(int)me->query_skill("mantian-huayu", 1);
           damage = damage*5;
           damage = 1000 + damage/2+random(damage/2);
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「天山雪飘」只能对战斗中的对手使用。\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「天山雪飘」！\n");               
        if( (int)me->query_skill("kunlun-zhang", 1) < 200 )
                return notify_fail("你的「昆仑掌」火侯不够!\n");
//                 if( (int)me->query_skill("mantian-huayu", 1) < 200 )
//                 return notify_fail("你的「漫天花雨」火侯不够!\n");
                  if( (int)me->query_skill("xuantian-wuji", 1) < 200 )
                  return notify_fail("你的「玄天无极」火侯不够!\n");
              if( (int)me->query_skill("taxue-wuhen", 1) < 200 )
                return notify_fail("你的踏雪无痕火侯不够!\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「天山雪飘」!\n");
  message_vision(
  WHT "\n$N大喝一声[天山雪飘]！突然滴溜溜的转身，一招“天山雪飘”，掌影飞舞，霎时之间四面八方都是$N的身影,接着便一招快过一招.\n" NOR, me);
           if (random(me->query_skill("kunlun-zhang"))+lvl*7/10 > target->query_skill("force")/2 +target->query_skill("dodge")/2 )
        {
me->add_temp("apply/attack", lvl/10);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/attack", -lvl/10);
                me->start_busy(random(2)+2);
                target->start_busy(random(3));
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                 me->add("neili", -damage/8);

                if( damage < 40 )
         msg = MAG  "\n结果$n被$N攻了个措手不及，胸口中了一掌,闷哼一声.\n"NOR;
          else if( damage < 80 )

     msg = HIR "$n看$N出招加快一阵慌乱，被$N以双掌打在胸口,有如受到一记重锤，连退了五六步！\n"NOR;

        else if( damage < 160 )

        msg = RED "\n$n只觉的四周都是$N的身影眼睛一花,结果被$N的双掌击中胸口，眼前一黑，象一捆稻草一样飞了出去！\n"NOR;
                else
        msg = RED "\n$n只觉的四周都是$N的身影眼睛一花,结果被$N的双掌击中胸口，眼前一黑，象一捆稻草一样飞了出去！\n"NOR;
}
        else 
        {
                   me->start_busy(random(3));
                me->add("qi", -(damage/2));
                me->add("eff_qi", -(damage/5));
    msg = HIY"\n$n看破了$N的企图，身形一转，急忙往外串出数丈,惊出一身泠汗。\n"NOR;
        }
       message_vision(msg, me, target);
        return 1;
}

