//qixing.c 全真剑法 七星绝命剑  
//shezhou code   
//5.12 2002 by aya 

#include <ansi.h> 
inherit F_DBASE;
inherit F_SSERVER; 
int perform(object me, object target) 
{
        object weapon;
        int ap,dp, amount,damage,dam;  
        string str;
        if( !target ) target = offensive_target(me);
        if( !target  
        ||      !target->is_character()  
        ||      !me->is_fighting(target) ) 
                return notify_fail("七星绝命剑只能对战斗中的对手使用。\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))  
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if( me->query_skill("xiantian-gong", 1) < 200 ) 
                return notify_fail("你的先天气功不够纯熟！\n");   
        if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("夺命七星必须用先天气功引导内力流动才行！\n");   
        if( me->query_skill("quanzhen-jian",1) < 200 )   
                return notify_fail("你全真剑法不够纯熟！\n"); 
        if( me->query("neili") <= 500 )  
                return notify_fail("你的内力不够使用七星绝命剑 ！\n"); 
        if( me->query("jingli") <= 500 ) 
                return notify_fail("你的精力不够使用七星绝命剑 ！\n");

        message_vision(HBBLU"$N一声长啸，一抖手中剑，顿时形成一道剑幕，就在$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n"NOR,me,target);            

        amount = (int)me->query_skill("sword")/4; 
        if ( amount < 60 ) amount = 60;
        if ( amount > 100 ) amount = 100;
         me->add_temp("apply/damage",amount*2); 
         me->add_temp("apply/attack",amount*3);   
         message_vision(HIR"\n→ → → → → → → → → →【夺】！" NOR, me, target);   
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIR"\n→ → → → → → → → → →【命】！" NOR, me, target);  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
         message_vision(HIR"\n→ → → → → → → → → →【七】！" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIR"\n→ → → → → → → → → →【星】！" NOR, me, target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

        if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)     
        {   
        ap=me->query_skill("sword",1)+me->query_skill("xiantian-gong")/4;
        dp=target->query_skill("parry",1);
        if ((random(ap)>dp/2) &&     
          (me->query_skill("quanzhen-jian",1)>300)) {  
                        message_vision(HIW"$P剑势未尽，潜运内力，一抖手中"+weapon->name()+HIW"，剑幕中一道白光，凌厉至极，在$p身上刺了个透明窟窿！\n" NOR, me, target);      
                       dam=me->query_skill("quanzhen-jian",1)*(random(3)+2);
                       target->receive_wound("qi", dam/2);   
                       target->receive_damage("qi",dam); 
                       me->add("neili", -me->query("jiali")-300);
                       me->add("jingli", -100);     
                       COMBAT_D->report_status(target);  
             }  
         else      
         {   
               me->add("neili", -100); 
               me->add("jingli", -50);  
               me->start_busy(2);  
               message_vision(HIY"$p轻轻一笑，趁$P气息不稳,伸出两指，弹在$P的剑上，剑幕顿时散乱。\n" NOR,me,target);      
          }  
        }  
         me->start_busy(random(4)+1);  
         me->add("neili", -amount*3);   
         me->add("jingli", -amount*2); 
         me->add_temp("apply/damage",-amount*2);       
         me->add_temp("apply/attack",-amount*3);   
         return 1; 
}
