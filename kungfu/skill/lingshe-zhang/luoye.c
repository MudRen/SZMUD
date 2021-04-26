//By tracy
//luoye.c 扫落叶
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int ap,dp, amount,damage;
        string str;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("【狂风扫落叶】只能对战斗中的对手使用。\n");
//       if( !wizardp(me)) return notify_fail("暂时并未开放此技能。\n");
        if( me->query_skill_mapped("force") != "hamagong" )
                return notify_fail("你所用的并非蛤蟆功，无法使用【狂风扫落叶】！\n");
        if( me->query_skill("hamagong", 1) < 100 )
                return notify_fail("你的蛤蟆功火不够纯熟！\n");
        if( me->query_skill("lingshe-zhang",1) < 120 )
                return notify_fail("你灵蛇杖不够纯熟！\n");
                weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("你手中无杖，如何能够施展【狂风扫落叶】？\n");
        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够使用【狂风扫落叶】！\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("你的精力不够使用【狂风扫落叶】！\n");
        amount = (int)me->query_skill("staff")/4;
        if ( amount < 60 ) amount = 60;
        if ( amount > 90 ) amount = 90;  
         me->add_temp("apply/damage",amount*2);
         me->add_temp("apply/attack",amount*3);
         message_vision(BLU "\n$N身形一晃，一招【狂风扫落叶】，手中的"+(me->query_temp("weapon"))->query("name")+BLU"如暴风骤雨般疯狂扫向$n肩头！\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
         message_vision(HIR "紧跟着"+(me->query_temp("weapon"))->query("name")+HIR"交置左手，同时舞出重重杖影插向$n小腹！\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
         message_vision(HIR "一招未落，一招又起，$N逆转手中的"+(me->query_temp("weapon"))->query("name")+HIR"直劈$n的面门，三招一气呵成动作之快让人匪夷所思！\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if (me->query_skill("lingshe-zhang",1)>200) 
        {
         message_vision(HIR "$N不等$n缓过神来,将手中"+(me->query_temp("weapon"))->query("name")+HIR"一横，又是一式【狂风扫落叶】，攻势更加猛烈。\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        }
      if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)
      {
        if (me->query_skill("lingshe-zhang",1)>300) 
        {
                 
        ap=me->query("combat_exp")/1000+me->query_skill("staff",1)+me->query_skill("hamagong")/4;
        dp=target->query("combat_exp")/1000+target->query_skill("parry",1);
        message_vision(BLU"\n突然间$N双目精光四射。将"+(me->query_temp("weapon"))->query("name")+BLU"抛向空中,紧跟着高高跃起,将蛤蟆功运劲于掌,双掌猛的击在"+(me->query_temp("weapon"))->query("name")+BLU"柄上。\n只见"+(me->query_temp("weapon"))->query("name")+BLU"挟风携势卷起一阵狂风直射向$n。\n"NOR,me,target);       
          if(random(ap)>dp/2){     
                  damage=me->query_skill("lingshe-zhang",1)*(random(5)+2);     
                if (damage<700) damage=700;           
                if (damage>target->query("qi") ) {   
                        message_vision(HIR"\n只见$n躲闪不及，已被"+(me->query_temp("weapon"))->query("name")+HIR"击中心口，一声惨叫，身子已飞出丈许。\n"NOR, me, target);                                  
                        target->receive_wound("qi", random(target->query("eff_qi")),me);
                        target->receive_damage("qi",target->query("qi")+1,me);
                }   
                else
                {
                        message_vision(HIR"\n只见$n躲闪不及，已被"+(me->query_temp("weapon"))->query("name")+HIR"击中小腹，看来伤势不轻。\n"NOR, me, target);                         
                        target->receive_wound("qi", random(damage), me);
                        target->receive_damage("qi", damage, me);
                }
                        me->add("neili", -me->query("jiali")-200);
                        me->add("jingli", -me->query("jiajin")-100);                              
                str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
          } 
          else 
          {
                me->add("neili", -me->query("jiali")-200);
                me->add("jingli", -me->query("jiajin")-100); 
                me->start_busy(2);   
                message_vision(HIY"\n$n见此招来势凶猛，高高越起，轻巧地躲了。\n"NOR,me,target);
          }
        }
      }
         me->start_busy(random(4)+1);
         me->add("neili", -amount*3);
         me->add("jingli", -amount*2);
         me->add_temp("apply/damage",-amount*2);
         me->add_temp("apply/attack",-amount*3);
         return 1;
}
