//Code of Shenzhou
//coding by Slow
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me);
void checking(object me);

int exert(object me, object target)
{
          int lv;

             if (!me->query("canewhua"))  return notify_fail("你还没得到化功大法的真传。\n");
              if (me->query("family/family_name") != "星宿派")
          return notify_fail("化功大法是星宿派的独门绝学。\n");
                lv = (int)me->query_skill("huagong-dafa", 1); 
           if( target == me) target=offensive_target(me);
           if( !target )target = offensive_target(me);
      if( !target ) target = me->select_opponent();
/*
           if( !target||!me->is_fighting() )
                    return notify_fail("化功大法只能对战斗中的对手使用。\n");
*/
          if( me->query_temp("newhua") )
                    return notify_fail("你已经施展出化功大法了！\n");


              if( me->query_skill("huagong-dafa", 1) < 360 )
                  return notify_fail("你的化功大法火候未到！\n");

        if( me->query_skill_mapped("force") != "huagong-dafa")
                  return notify_fail("你所运使的内功并非化功大法，无法施展开来！\n");

          if( me->query("neili") <= 3000 )
                  return notify_fail("你的内力不足以施展化功大法！\n");

          if( me->query("jingli") <= 2500 )
                  return notify_fail("你的精力不足以施展化功大法！\n");
/*
            if ((int)me->query_skill("pixie-jian", 1) >=1)
          return notify_fail("辟邪剑法与化功大法的修炼方法相悖，无法施展化功大法的高深功夫！\n");
*/
        if( me->query_skill_mapped("sword") == "pixie-jian" ||
        me->query_skill_mapped("parry") == "pixie-jian" ||
        me->query_skill_mapped("dodge") == "pixie-jian" )
          return notify_fail("辟邪剑法与化功大法的修炼方法相悖，同时施展化功大法和辟邪剑法！\n");
        if(me->is_busy())
                  return notify_fail("你正忙着呢,没办法施展化功大法! \n");

message_vision(
HIB"$N突然面色阴暗下来，干笑几声，陡然加快身法，将一双大袖舞得呼呼风响。\n"
HIG"只见$N越舞越快满场游走，化功大法激发出的真气布满$N的两只袖袍，象鼓足的风帆。\n"
HIB"四处弥漫的真气将空气挤成一股股汹涌澎湃的气浪。\n" NOR, me, target ); 


           me->set_temp("newhua",(int)me->query_skill("huagong-dafa", 1)/10+10);
               call_out("checking", 1, me); 
        return 1;
}

  void checking(object me)
{
              int num,ap,dp,dmg;
          object target;

if(!me) return;
          if (!me->query_temp("newhua")) return;
        target = me->query_temp("offensive_target");
          num=(int)me->query_temp("newhua");

        if( me->query_skill_mapped("sword") == "pixie-jian" ||
         me->query_skill_mapped("parry") == "pixie-jian" ||
        me->query_skill_mapped("dodge") == "pixie-jian" )
         {
         me->delete_temp("newhua");
         message_vision(HIY "\n$N用辟邪剑法与化功大法的修炼方法相悖，同时施展化功大法和辟邪剑法！！\n"NOR, me);;
          return;
           }
           me->set_temp("newhua",me->query_temp("newhua")-1);
       if( wizardp(me) )  tell_object(me,sprintf("<持续时间还剩%d秒>\n",num));
          if( num<1 ) {
  message_vision(YEL"$N渐感内力不支，不得已将已发挥到极致的「化功大法」缓缓收回丹田。\n"NOR, me);
           me->delete_temp("newhua");
                return;
        }
          if( !target ) target = offensive_target(me);
          if( !target || !target->is_character() || !me->is_fighting(target) )
          {
//        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
           call_out("checking", 1, me); 
            return;
          }


        if( !living(me) || me->is_ghost()  )
        {
                  remove_effect(me);
                return;
        }
/*
        if( !target || environment(me) != environment(target) || !me->is_fighting() )
        {
                  tell_object(me, "\n你不在战斗中,只好收回了化功大法。\n" );
            me->delete_temp("newhua");
                return;
        }
*/
         ap=me->query("combat_exp");
         dp=target->query("combat_exp");
              if (random(15)>4)
          {
         if(ap>random(dp*5/4))
         {
              message_vision( 
HIR "$n刚刚靠近$N，只觉得一股阴冷无比的气浪扑来要将自己卷裹进去，连忙运功布气。\n"
CYN "$N冷哼一声，黑气腾腾的双手已抓住$n的脉门大穴，$n疼入骨髓不由发出凄厉惨叫。\n" NOR, me, target ); 
                      tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR); 
                      tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR); 
                dmg=(int)me->query_skill("force")*4 +random(600);
                target->receive_damage("qi", dmg, me ); 
                       target->receive_wound("qi", dmg/2+random(dmg/2), me); 
            me->add("qi", (int)me->query_skill("force") ); 
             COMBAT_D->report_status(target);
               target->start_busy(random(3));
          }
     }
        else{
              message_vision( 
HIB"忽见三条"+HIW+"银线"+HIB+"从$N的百会、左右太阳穴如冰蚕延行般直入眉心。\n"
HIB"$N额头已隐隐罩上一层殷蓝之气，突然身形一转袖袍狂舞变化出重重身影，身影中似有无数利爪向$n抓去。\n"
HIB"$N脸色越发阴暗，身上的玉笛在真气的鼓荡之下发出刺耳嗡鸣扰得$n心烦意乱，攻势不由得减缓了下来。\n"
HIW"$N见$n略显颓势，长啸一声将鼓足真气双袖象两堵高墙一般砸了过去，$n只得格架却将膻中穴暴露无遗。\n" NOR, 
                           me, target ); 
   if(ap>random(dp*5/4))
            {
                      message_vision( 
                              HIR "$N顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！\n\n" NOR, 
                              target ); 
                      tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR); 
                      if ((int)target->query("neili") > (int)me->query_skill("force")) 
                      { 
                               target->add("neili", -(int)me->query_skill("force")*3/2 ); 
                               me->add("neili", ((int)me->query_skill("force"))/2); 
                      }else{ 
                               me->add("neili", ((int)me->query_skill("force"))/5); 
                              target->set("neili", 0); 
                      } 
          }
       }
                            call_out("checking", 1+random(5), me); 
        return;
}

  void remove_effect(object me) 
{
        if (!me) return;
          me->delete_temp("newhua");
        me->start_busy(1);
}
