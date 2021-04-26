// Code of ShenZhou
// cimu.c ��а��������Ŀ��֮��
// Modified by xQin 6/99
// Modified by wzfeng@xkx 99 9
// Fixed cimu could recover bug, sdong, 12/15/1999

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "pixie_superskill.c"

void remove_cimu(object, int);

int perform(object me, object target)
{
        string dodge_skill,perform_name;
        object weapon;
        int level, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ֻ�ܴ�ս���еĶ��ֵ��۾���\n");
        if( (int)target->query_temp("pixie/cimu") )
                return notify_fail(target->name() +"�ѱ�����У�\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");

        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("����ָ��Ŀ��\n");
        if(me->query_skill("pixie-jian",1)<400)
        {
        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                        return notify_fail("��û�г��ֵı���������ʩչ����Ŀ��������\n");
                        }

        if( weapon->query("skill_type") != "sword" )
                  return notify_fail("��û�г��ֵı���������ʩչ����Ŀ��������\n");

        if( (level = (int)me->query_skill("pixie-jian", 1)) < 80 )
                return notify_fail("��ı�а����������죬�޷�ʹ������Ŀ��������\n");

        if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ����ѽӽ����֡�\n");    

         message_vision(HIB"\n�����$N���������ϣ�˫�����õ��ģ���������֮����\n"NOR, me);
        tell_object(target, HIR"�㲻���󺧣�������Ӱ����������һ�����Լ�˫Ŀ������\n"NOR);
         perform_name="pixie-cimu";

                        me->add("neili", -(20+random(40)));
            me->add("jingli", -(40+random(80)));
                  if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

                ap = me->query_skill("sword")+me->query_skill("dodge")/2;
                dp = target->query_skill("dodge");
                if(me->query("dex")>20)
                        ap+=ap/2;

        if( target->is_busy() ) dp += dp/2;

        if( random(ap+dp) < dp )
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                message_vision(HIG+SKILL_D(dodge_skill)->query_dodge_msg()+NOR, me, target);
                                me->delete_temp("pixie_performtime");
        }
        else
        {
                        if(random(target->query_temp("pixie_times/cimu"))>1+random(10)

                                &&random(target->query_int())>random(me->query_int()))
                                {
                                message_vision(HIG"$p��ǰ���й����У�֪������е��������������з���������һ�������ţ��ܿ������һ����\n" NOR,me);
                                me->start_busy(1 + random(3));
                                me->delete_temp("pixie_performtime");
                                return 1;
                                }
                        
                tell_object(target, "��˫��һ�ڣ���Ҳ�Ʋ�����ô��\n");
                if( userp(target) )
                                {
                        target->set_temp("cimu_power", level/3);
                                                target->apply_condition("blind",1+level/80);
                                }

                message_vision(HIB"$N����Ʈ����������ȣ�ת�˼�ת�����ݳ�ȥ������֮��֮�죬ֱ�Ƿ�����˼��\n"NOR, me);
                message_vision(HIR"ֻ��$N˫��������������ϸ��Ѫ�ߣ������գ�ֱ�ҵ���򤡣\n"NOR, target);


                target->add_temp("apply/attack", -level/3);
                target->add_temp("apply/defense", -level/3);
                target->set_temp("pixie/cimu", 1);
                                target->add_temp("pixie_times/cimu",1 );
                                
                                        set_perform(me,perform_name);
                                    me->set_temp("pixie_performtime",5);

                                        //target->start_call_out( (: call_other, __FILE__, "remove_effect", target, level/3 :), level/30);
                }
                                        me->start_busy(1 + random(2));

                                        if(!me->query_temp("pixie_noop"))
                                        call_out("checking_pixieflg", 1, me, target);
                

                  return 1;
}

/*
void remove_effect(object me,int level)
{
                if( !me | !objectp(me) ) return;

        if( userp(me) && living(me) )
me->delete_temp("block_msg/all");

        me->add_temp("apply/attack", level);
        me->add_temp("apply/defense", level);
        tell_object(me, HIC"��������ָ������ˡ�\n"NOR);
        me->delete_temp("pixie/cimu");

                return;
}


*/
