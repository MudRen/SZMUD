// shexing.c 蛇行
// CODE BY SCATTER

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl, player, opp, diff;
          string strMsg;

      lvl = ((int)me->query_skill("xiaoyaoyou", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
          
          if( !target ) target = offensive_target(me);
          if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail("「意影蛇行」之技只能在战斗中对敌人使用。\n");
          if( me->is_busy() )
                  return notify_fail("你还在忙呀！\n");
      if( (int)me->query_skill("xiaoyaoyou",1) < 150 )
                  return notify_fail("你的逍遥游不够娴熟，不能使出意影蛇行！\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 150 )
                  return notify_fail("你的逍遥游不够娴熟，不能使出意影蛇行！\n");
      if( (int)me->query_skill("huntian-qigong", 1) < 150 )
                  return notify_fail("你的混天气功等级不够，不能使出意影蛇行！\n");
      if( (int)me->query("max_neili") < 1000 )
                  return notify_fail("你的内力太弱，不能使出意影蛇行！\n");
      if( (int)me->query("neili") < 200 )
                  return notify_fail("你的内力太少了，不能使出意影蛇行！\n");   
          if( (int)me->query("neili") < 300 )
                  return notify_fail("你的精力太少了，不能使出意影蛇行！\n");   
          if(!me->query_temp("gb_huixuan"))
                  return notify_fail("你没有使出逍遥回旋步，无法使出意影蛇行！\n");   

          strMsg = MAG+"$N双手的攻击招数突然改变，有时慢，有时快，有时偏，有时准，$n感到极难应付。\n\n"+NOR;

          player = lvl * 4 / 3;
          opp = ((int)target->query_skill("force", 1)+(int)me->query_skill("dodge", 1))/2;
          diff = player - opp;

          if(diff < 1)
          {
                  strMsg = strMsg + HIR + "此时$N使出全力，顿时间发现破绽露出，只见$n很轻松的闪开$N的攻击。\n"+NOR;
                  me->start_busy(2 + random(2));
          }

          else if(diff < 50)
          {
                  strMsg = strMsg + HIC + "此时$N抓到$n武功的要害，使出十成功力在短时间内只攻不守。\n"+NOR;
                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$n使出本门轻功并解正面迎敌将$N使出十成功力瞬间消为六成。\n"+NOR;
                  me->start_busy(1 + random(3));
          }

          else if(diff < 100)
          {
                  strMsg = strMsg + HIW + "此时$N猛攻$n上，中，下三处，$n顿时感到无法闪躲只好强迫招架。\n"+NOR;

                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$n摆出招架的姿势看准了$N的攻击目标，$n使用全力招架了几下发现自己像稻草一样的飞了出去。\n"+NOR;
                  me->start_busy(2 + random(3));
          }

          else
          {
                  strMsg = strMsg + HIW + "$N二话不说开始先发制人，$N双手向上攻击突然转变为向中间攻击，$N又瞬间改回向上攻击。\n"+NOR;

                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$n看着$N出的招数完全无法预测目标，$n被$N就以" + HIC + "上" + HIW + "，" + HIR + "中" + HIW + "，" + HIG + "下" + HIW + "，闪电般的攻击丝毫没有反击能力。\n"+NOR;
                  me->start_busy(1 + random(4));

          }
          
          COMBAT_D->report_status(target);

      return 1;
}

