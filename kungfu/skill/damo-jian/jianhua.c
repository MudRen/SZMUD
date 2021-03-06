// damo-jian 剑花    

#include <ansi.h>    
#include <combat.h> 
inherit F_SSERVER; 

int perform(object me, object target)    
{  
        object weapon;
        int damage; 
        string msg;    
                return notify_fail("「剑花」暂时关闭。\n");  

        if( !target ) target = offensive_target(me); 

        if( !target || !target->is_character() || !me->is_fighting(target) )  
                return notify_fail("「剑花」只能对战斗中的对手使用。\n");  

        if (!objectp(weapon = me->query_temp("weapon"))  
        || (string)weapon->query("skill_type") != "sword")  
                return notify_fail("你使用的武器不对。\n");   

        if( (int)me->query_skill("damo-jian", 1) < 150 )     
                return notify_fail("你的达摩剑不够娴熟，不会使用。\n"); 

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 150 ) 
                return notify_fail("你的混元一气修为不够高。\n"); 

        if( (int)me->query("neili") < 300 )  
                return notify_fail("你现在内力太弱，不能使用「剑花」。\n");   

        message_vision(HIM"$N一"HIC"跃"HIM"而"HIG"起"NOR"，"HIR"手腕"HIM"一抖"NOR"，"HIC"挽"HIM"出一个"YEL"美丽"HIM"的"HIW"剑花"NOR"，"HIM"飞向$n"NOR"。\n"NOR,me,target); 

        if (random(me->query_skill("force")) > target->query_skill("force")/4 )
        {     

                damage = (int)me->query_skill("force", 1);   
                damage = damage*4 +  (int)me->query_skill("damo-jian", 1);
                damage = damage*4 +  (int)me->query_skill("sword", 1);   
                if (wizardp(me)) printf("damage = %d \n",damage);
                target->receive_damage("qi", damage);   
                target->receive_wound("qi", damage/2); 
                me->add("neili", -300);
message_vision("只见$N"HIY"人剑合一"NOR"，穿向$n，$n只觉一股热流穿"HIR"心而过"NOR"，喉头一"HIB"甜"NOR"，"HIR"鲜血狂喷而出！\n"NOR,me,target);;

                me->start_busy(1); 
                COMBAT_D->report_status(target);  
        } else    
        {    
            message_vision(HIY"可是$n猛地向边上一跃,跳出了$N的攻击范围。\n"NOR,me,target);  
                me->add("neili", -100);
                me->start_busy(1); 
        }   

        if(userp(target)) target->fight_ob(me);  
        return 1;      
}
