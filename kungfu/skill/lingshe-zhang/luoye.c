//By tracy
//luoye.c ɨ��Ҷ
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
                return notify_fail("�����ɨ��Ҷ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
//       if( !wizardp(me)) return notify_fail("��ʱ��δ���Ŵ˼��ܡ�\n");
        if( me->query_skill_mapped("force") != "hamagong" )
                return notify_fail("�����õĲ��Ǹ�󡹦���޷�ʹ�á����ɨ��Ҷ����\n");
        if( me->query_skill("hamagong", 1) < 100 )
                return notify_fail("��ĸ�󡹦�𲻹����죡\n");
        if( me->query_skill("lingshe-zhang",1) < 120 )
                return notify_fail("�������Ȳ������죡\n");
                weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("���������ȣ�����ܹ�ʩչ�����ɨ��Ҷ����\n");
        if( me->query("neili") <= 500 )
                return notify_fail("�����������ʹ�á����ɨ��Ҷ����\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ�������ʹ�á����ɨ��Ҷ����\n");
        amount = (int)me->query_skill("staff")/4;
        if ( amount < 60 ) amount = 60;
        if ( amount > 90 ) amount = 90;  
         me->add_temp("apply/damage",amount*2);
         me->add_temp("apply/attack",amount*3);
         message_vision(BLU "\n$N����һ�Σ�һ�С����ɨ��Ҷ�������е�"+(me->query_temp("weapon"))->query("name")+BLU"�籩���������ɨ��$n��ͷ��\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
         message_vision(HIR "������"+(me->query_temp("weapon"))->query("name")+HIR"�������֣�ͬʱ���������Ӱ����$nС����\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
         message_vision(HIR "һ��δ�䣬һ������$N��ת���е�"+(me->query_temp("weapon"))->query("name")+HIR"ֱ��$n�����ţ�����һ���ǳɶ���֮�����˷�����˼��\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if (me->query_skill("lingshe-zhang",1)>200) 
        {
         message_vision(HIR "$N����$n��������,������"+(me->query_temp("weapon"))->query("name")+HIR"һ�ᣬ����һʽ�����ɨ��Ҷ�������Ƹ������ҡ�\n" NOR, me, target);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
        }
      if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)
      {
        if (me->query_skill("lingshe-zhang",1)>300) 
        {
                 
        ap=me->query("combat_exp")/1000+me->query_skill("staff",1)+me->query_skill("hamagong")/4;
        dp=target->query("combat_exp")/1000+target->query_skill("parry",1);
        message_vision(BLU"\nͻȻ��$N˫Ŀ�������䡣��"+(me->query_temp("weapon"))->query("name")+BLU"�������,�����Ÿ߸�Ծ��,����󡹦�˾�����,˫���͵Ļ���"+(me->query_temp("weapon"))->query("name")+BLU"���ϡ�\nֻ��"+(me->query_temp("weapon"))->query("name")+BLU"Ю��Я�ƾ���һ����ֱ����$n��\n"NOR,me,target);       
          if(random(ap)>dp/2){     
                  damage=me->query_skill("lingshe-zhang",1)*(random(5)+2);     
                if (damage<700) damage=700;           
                if (damage>target->query("qi") ) {   
                        message_vision(HIR"\nֻ��$n�����������ѱ�"+(me->query_temp("weapon"))->query("name")+HIR"�����Ŀڣ�һ���ҽУ������ѷɳ�����\n"NOR, me, target);                                  
                        target->receive_wound("qi", random(target->query("eff_qi")),me);
                        target->receive_damage("qi",target->query("qi")+1,me);
                }   
                else
                {
                        message_vision(HIR"\nֻ��$n�����������ѱ�"+(me->query_temp("weapon"))->query("name")+HIR"����С�����������Ʋ��ᡣ\n"NOR, me, target);                         
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
                message_vision(HIY"\n$n�������������ͣ��߸�Խ�����ɵض��ˡ�\n"NOR,me,target);
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
