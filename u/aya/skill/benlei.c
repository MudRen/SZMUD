// ����(benlei.c)
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
                return notify_fail("�����ס�ֻ����ս���жԶ���ʹ�á�\n"); 

        if( !weapon || weapon->query("skill_type") != "sword") 
                return notify_fail("�����ʹ����������ʹ�á����ס���\n"); 

        if((int)me->query_skill("damo-jian", 1) < 150 ) 
                return notify_fail("��Ĵ�Ħ����������죬ʹ���������ס�������\n");     

        if((int)me->query_skill("hunyuan-yiqi", 1) < 150 )
                return notify_fail("��Ļ�Ԫһ�����ȼ���������ʹ���������ס�������\n"); 

        if((int)me->query_skill("force") < 150 )  
                return notify_fail("����ڹ��ȼ�����������ʹ�á����ס���\n");

        if((int)me->query_str() < 35 )   
                return notify_fail("�������������ǿ����ʹ���������ס�����\n");

        if( me->query_skill_mapped("sword") != "damo-jian" && userp(me))  
                return notify_fail("�������޷�ʹ�á����ס���\n"); 

        if( me->query_skill_mapped("parry") != "damo-jian" && userp(me))  
                return notify_fail("�������޷�ʹ�á����ס���\n"); 

        if( target->query_temp("dmj/benlei")) 
                return notify_fail(target->name()+"���Թ˲�Ͼ������Է��ĵؽ�����\n");    

        if((int)me->query("max_neili") < (me->query_skill("force")+j+200) )
                return notify_fail("����������̫����ʹ���������ס���\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("����������̫����ʹ���������ס���\n");

        message_vision(HIR"\n$N��"+weapon->query("name")+HIR"�������Ȱ�����̣����б���������ǧâӰ��ˮ��к�������˳�����$n��ȥ��\n"NOR,me,target); 
        if (random(me->query_skill("sword")) > target->query_skill("dodge")/3 
         || me->query("combat_exp", 1) > target->query("combat_exp", 1)*10  
         || !living(target)){      
            message_vision(HIY"���$nȫ���������γɵ������������ţ��������á�\n"NOR,me,target);  
            target->start_busy(2);
            target->set_temp("dmj/benlei", 1);
            me->add("neili", -200); 
            if (present(target,environment(me)) && me->is_fighting(target))
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
            me->start_perform(4, "�����ס�"); 
            if( me->query_skill("damo-jian", 1) > 150)
            call_out("remove_effect", 1, me, target);  
            if((int)me->query_skill("damo-jian", 1) > 150 
             &&(int)me->query("neili", 1) > (me->query_skill("force")+j)
             && present(target,environment(me))
             && me->is_fighting(target)){ 
               message_vision(HIR"\n$N�ְ�����������ׯ��,���е�"+weapon->query("name")+HIR"��Ȼ�������֮������$nϯ���ȥ��\n"NOR,me,target);   
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
                  me->start_perform(6,"�����ס�"); 
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
