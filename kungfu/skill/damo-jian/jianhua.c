// damo-jian ����    

#include <ansi.h>    
#include <combat.h> 
inherit F_SSERVER; 

int perform(object me, object target)    
{  
        object weapon;
        int damage; 
        string msg;    
                return notify_fail("����������ʱ�رա�\n");  

        if( !target ) target = offensive_target(me); 

        if( !target || !target->is_character() || !me->is_fighting(target) )  
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");  

        if (!objectp(weapon = me->query_temp("weapon"))  
        || (string)weapon->query("skill_type") != "sword")  
                return notify_fail("��ʹ�õ��������ԡ�\n");   

        if( (int)me->query_skill("damo-jian", 1) < 150 )     
                return notify_fail("��Ĵ�Ħ��������죬����ʹ�á�\n"); 

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 150 ) 
                return notify_fail("��Ļ�Ԫһ����Ϊ�����ߡ�\n"); 

        if( (int)me->query("neili") < 300 )  
                return notify_fail("����������̫��������ʹ�á���������\n");   

        message_vision(HIM"$Nһ"HIC"Ծ"HIM"��"HIG"��"NOR"��"HIR"����"HIM"һ��"NOR"��"HIC"��"HIM"��һ��"YEL"����"HIM"��"HIW"����"NOR"��"HIM"����$n"NOR"��\n"NOR,me,target); 

        if (random(me->query_skill("force")) > target->query_skill("force")/4 )
        {     

                damage = (int)me->query_skill("force", 1);   
                damage = damage*4 +  (int)me->query_skill("damo-jian", 1);
                damage = damage*4 +  (int)me->query_skill("sword", 1);   
                if (wizardp(me)) printf("damage = %d \n",damage);
                target->receive_damage("qi", damage);   
                target->receive_wound("qi", damage/2); 
                me->add("neili", -300);
message_vision("ֻ��$N"HIY"�˽���һ"NOR"������$n��$nֻ��һ��������"HIR"�Ķ���"NOR"����ͷһ"HIB"��"NOR"��"HIR"��Ѫ���������\n"NOR,me,target);;

                me->start_busy(1); 
                COMBAT_D->report_status(target);  
        } else    
        {    
            message_vision(HIY"����$n�͵������һԾ,������$N�Ĺ�����Χ��\n"NOR,me,target);  
                me->add("neili", -100);
                me->start_busy(1); 
        }   

        if(userp(target)) target->fight_ob(me);  
        return 1;      
}
