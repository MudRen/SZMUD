//qixing.c ȫ�潣�� ���Ǿ�����  
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
                return notify_fail("���Ǿ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))  
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if( me->query_skill("xiantian-gong", 1) < 200 ) 
                return notify_fail("������������������죡\n");   
        if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("�������Ǳ����������������������������У�\n");   
        if( me->query_skill("quanzhen-jian",1) < 200 )   
                return notify_fail("��ȫ�潣���������죡\n"); 
        if( me->query("neili") <= 500 )  
                return notify_fail("�����������ʹ�����Ǿ����� ��\n"); 
        if( me->query("jingli") <= 500 ) 
                return notify_fail("��ľ�������ʹ�����Ǿ����� ��\n");

        message_vision(HBBLU"$Nһ����Х��һ�����н�����ʱ�γ�һ����Ļ������$n����֮�䣬��Ļ�зɳ��߶亮�ǣ������ǰ�����$n��\n"NOR,me,target);            

        amount = (int)me->query_skill("sword")/4; 
        if ( amount < 60 ) amount = 60;
        if ( amount > 100 ) amount = 100;
         me->add_temp("apply/damage",amount*2); 
         me->add_temp("apply/attack",amount*3);   
         message_vision(HIR"\n�� �� �� �� �� �� �� �� �� �����᡿��" NOR, me, target);   
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIR"\n�� �� �� �� �� �� �� �� �� ����������" NOR, me, target);  
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
         message_vision(HIR"\n�� �� �� �� �� �� �� �� �� �����ߡ���" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIR"\n�� �� �� �� �� �� �� �� �� �����ǡ���" NOR, me, target); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

        if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)     
        {   
        ap=me->query_skill("sword",1)+me->query_skill("xiantian-gong")/4;
        dp=target->query_skill("parry",1);
        if ((random(ap)>dp/2) &&     
          (me->query_skill("quanzhen-jian",1)>300)) {  
                        message_vision(HIW"$P����δ����Ǳ��������һ������"+weapon->name()+HIW"����Ļ��һ���׹⣬������������$p���ϴ��˸�͸��������\n" NOR, me, target);      
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
               message_vision(HIY"$p����һЦ����$P��Ϣ����,�����ָ������$P�Ľ��ϣ���Ļ��ʱɢ�ҡ�\n" NOR,me,target);      
          }  
        }  
         me->start_busy(random(4)+1);  
         me->add("neili", -amount*3);   
         me->add("jingli", -amount*2); 
         me->add_temp("apply/damage",-amount*2);       
         me->add_temp("apply/attack",-amount*3);   
         return 1; 
}
