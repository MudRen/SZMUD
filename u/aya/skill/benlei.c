// 奔雷(benlei.c)
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER; 

int perform(object me, object target)  
{
        string msg,dodge_skill;
        int j; 
        object weapon; 
        j = me->query_skill("sword", 1);   
        weapon = me->query_temp("weapon"); 

        if( !target ) target = offensive_target(me);  

        if( !target || !me->is_fighting(target) ) 
                return notify_fail("「奔雷」只能在战斗中对对手使用。\n"); 

        if( !weapon || weapon->query("skill_type") != "sword") 
                return notify_fail("你必须使用武器才能使用「奔雷」！\n"); 

        if((int)me->query_skill("damo-jian", 1) < 150 ) 
                return notify_fail("你的达摩剑还不够娴熟，使不出「奔雷」绝技。\n");     

        if((int)me->query_skill("hunyuan-yiqi", 1) < 150 )
                return notify_fail("你的混元一气功等级还不够，使不出「奔雷」绝技。\n"); 

        if((int)me->query_skill("force") < 150 )  
                return notify_fail("你的内功等级不够，不能使用「奔雷」。\n");

        if((int)me->query_str() < 35 )   
                return notify_fail("你的膂力还不够强劲，使不出「奔雷」来。\n");

        if( me->query_skill_mapped("sword") != "damo-jian" && userp(me))  
                return notify_fail("你现在无法使用「奔雷」！\n"); 

        if( me->query_skill_mapped("parry") != "damo-jian" && userp(me))  
                return notify_fail("你现在无法使用「奔雷」！\n"); 

        if( target->query_temp("dmj/benlei")) 
                return notify_fail(target->name()+"正自顾不暇，你可以放心地进攻。\n");    

        if((int)me->query("max_neili") < (me->query_skill("force")+j+200) )
                return notify_fail("你现在内力太弱，使不出「奔雷」。\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，使不出「奔雷」。\n");

        message_vision(HIR"\n$N持"+weapon->query("name")+HIR"化作鬼魅般的轾烟，手中宝剑化成万千芒影，水银泻地又似浪潮般往$n攻去。\n"NOR,me,target); 
        if (random(me->query_skill("sword")) > target->query_skill("dodge")/3 
         || me->query("combat_exp", 1) > target->query("combat_exp", 1)*10  
         || !living(target)){      
            message_vision(HIY"结果$n全身被剑气所形成的气涡所笼罩着，动弹不得。\n"NOR,me,target);  
            target->start_busy(2);
            target->set_temp("dmj/benlei", 1);
            me->add("neili", -200); 
            if (present(target,environment(me)) && me->is_fighting(target))
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
            me->start_perform(4, "「奔雷」"); 
            if( me->query_skill("damo-jian", 1) > 150)
            call_out("remove_effect", 1, me, target);  
            if((int)me->query_skill("damo-jian", 1) > 150 
             &&(int)me->query("neili", 1) > (me->query_skill("force")+j)
             && present(target,environment(me))
             && me->is_fighting(target)){ 
               message_vision(HIR"\n$N手按剑柄，宝相庄严,手中的"+weapon->query("name")+HIR"忽然发出轰轰之声，向$n席卷而去。\n"NOR,me,target);   
               if(random(me->query_skill("sword")) > target->query_skill("parry")/3  
                || ! living(target)  
                || me->query("combat_exp", 1) > target->query("combat_exp", 1) * 10 ){           
                  me->add_temp("apply/damage", j*4);
                  me->add_temp("apply/attack", j*4);
                  me->set_temp("dmj_pfm", 1);
                  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                  if (present(target,environment(me)) && me->is_fighting(target))   
                  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
                  me->add_temp("apply/damage", -j*4); 
                  me->add_temp("apply/attack", -j*4);
                  if(userp(me))  
                     me->add("neili", -(me->query_skill("force")));  
                  else 
                  me->add("neili", -200); 
                  me->add("jingli", -150);
                  me->delete_temp("dmj_pfm");
                  me->start_busy(1);
                  me->start_perform(6,"「奔雷」"); 
               }  
               else {
                   me->add("neili", -100); 
                   dodge_skill = target->query_skill_mapped("dodge");
                   if( !dodge_skill ) dodge_skill = "dodge";   
                   msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                   message_vision(msg, me, target); 
               }  
               return 1;
            } 
        }  
        else {
               me->start_busy(1);
               me->add("neili", -100); 
               dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge"; 
               msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1); 
               message_vision(msg, me, target);   
        }  
        return 1; 
}

void remove_effect(object me, object target) 
{
        if( !me) return; 
        if( objectp(target) && !me->is_fighting(target)){ 
          target->delete_temp("dmj/benlei"); 
          return;
        }   
        if( objectp(target) 
         && me->is_fighting(target) 
         && !target->is_busy()
         && random(2) == 1 
         && me->query_temp("weapon")){ 
          target->delete_temp("dmj/benlei");  
          return; 
        }    
        call_out("remove_effect", 1 ,me ,target);
}
