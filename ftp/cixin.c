//Cracked by Kafei
// cimu.c ��а���������ġ�֮��
// wzfeng@XKX 99 9 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "pixie_superskill.c"

void remove_effect(object target,int parry_skill);



int perform(object me, object target)
{
        string msg,perform_name;
		
        object weapon;
		
		
        int  ap, dp,damage;
        if( !target ) target = offensive_target(me);

       	if(me->query("canuse_cixin")!=1)
			    return notify_fail("ʲô��\n");

		if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����ġ�֮��ֻ����ս���жԵ���ʹ�á�\n");
		if(!living(target))
			return notify_fail("�Ը����Ե��˻��衸���ġ�?\n");

        if(me->query_temp("pixie/guimei") <=0 )
                return notify_fail("��û��ʩչ������������ʹ�������ġ���\n");

        if( me->query("neili") <= 500)
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ���������\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("������Ρ����ġ�����\n");

        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����ġ�������\n");

        if( ( (int)me->query_skill("pixie-jian", 1)) < 180 )
                return notify_fail("��ı�а����������죬�޷�ʹ�������ġ���\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ����ѽӽ����֡�\n");	
		
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-cixin";

		ap = me->query_skill("sword")/2;
		dp = target->query_skill("dodge")/2+target->query_skill("parry")/3;
		
		if(random(me->query("dex")>20)||(random(me->query("int")>20)))
		{
			ap+=ap;
		}
		if(me->query("qi")<me->query("max_qi")/10)
			ap=ap*2;
		weapon = me->query_temp("weapon");
		msg="";

		//do super perform
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		
		{
			
		    if(target->query_temp("pixie/cimu"))
		 {
			msg = HIW "\n��$n˫Ŀʧ��֮ʱ��$Nһ����Ц��ʹ����а���������ġ�֮����\n"NOR;
			ap=ap+random(ap);
		}
			msg += HIB "$N��ҡ��֫����ӰƮ�����û�������������Ӱ��ͻȻһӰ�ɳ���Ϯ��$n��\n"NOR;
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				
		}

        if( random(ap) < random(dp)||(random(1)!=0))
        {
                msg += HIG"$n���þ������棬֪����$Nʩչ����ɱ�ţ��Ͻ���ס���ƣ�һ��б�������յıܿ���һ�С�\n" NOR;
	            me->start_busy(5 + random(3));

				me->delete_temp("pixie_performtime");

        }
        else
			if(!target->query_temp("pixie/cixin")
				&&random(target->query_temp("pixie_times/cixin"))>1
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p��ǰ�Ѽ������У��������з�����һ��б������Ȼ�����\n" NOR;
				me->start_busy(5 + random(3));
				me->delete_temp("pixie_performtime");

				}
			else
			{
					msg += HIR "$n֪����ǰ������������֪���²���������Ŀ�һ���ʹ���ѱ�$N���С�\n"NOR;	
					damage=me->query_skill("pixie-jian",1)*(random(5)+5);
					target->set_temp("pixie/cixin",1);
					target->add_temp("pixie_times/cixin",1 );
					target->add("eff_qi",-damage);
					target->add("jingli",-damage/2);

					set_perform(me,perform_name);
   				    me->start_busy(2 + random(3));


			}
		}

					if(!me->query_temp("pixie_noop"))
					call_out("checking_pixieflg", 1, me, target);
					
					me->add("neili", -400);
					me->add("jingli", -400);
					message_vision(msg, me, target);
                  return 1;
}
