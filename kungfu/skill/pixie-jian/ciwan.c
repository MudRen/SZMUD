// Code of ShenZhou
// cimu.c ��а����������֮��
// wzfeng@XKX 99 9 
// by snowyu fix ciwan add parry BUG 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "pixie_superskill.c"

void remove_effect(object target,int parry_skill);



int perform(object me, object target)
{
        string msg,perform_name;
		
        object weapon;
		
		
        int  ap, dp,ciwan_busy,attack_skill,parry_skill;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("������֮��ֻ����ս���жԵ���ʹ�á�\n");
		if(!living(target))
			return notify_fail("�Ը����Ե��˻��衸����?\n");


        if( (int)target->query_temp("pixie/ciwan") )
                return notify_fail("���Ѵ��е���˫��Ҫ����\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 300 )
                return notify_fail("��ľ���������\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("������Ρ����󡹣���\n");
        if( weapon->query("skill_type") != "sword" )
                      return notify_fail("����ʲô��������?\n");

/*        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����󡹾�����\n");
*/
        if( ( (int)me->query_skill("pixie-jian", 1)) < 120 )
                return notify_fail("��ı�а����������죬�޷�ʹ�������󡹡�\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ����ѽӽ����֡�\n");	
		
        //if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-ciwan";

		ap = me->query_skill("sword");
		dp = target->query_skill("dodge");
		if(me->query("dex")>19)
		{
			ap+=ap;
		}
		if(me->query("combat_exp")<(target->query("combat_exp")/3))
			ap=1;

		weapon = me->query_temp("weapon");
		msg="";
		parry_skill=target->query_skill("parry");
		if(parry_skill<=0)
			parry_skill=0;

		//�������ĸߵ������������ʱ�䡣
		if(me->query("dex")>22&&me->query("dex")>target->query("dex"))
			ciwan_busy=me->query_dex();
		else
			ciwan_busy=me->query_dex()/2;

		//do super perform
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		
		{
		    if(target->query_temp("pixie/cimu"))
		 {
			msg = HIB "\n��$n˫Ŀʧ��֮ʱ��$Nһ����Ц��ʹ����а����������֮����\n"NOR;
			ap=ap+random(ap);
		}
		
                    if(me->query_temp("pixie/guimei") >0 )
                    {
                    msg += HIB "$N����Ӱ�������һ�㣬ɲ�Ǽ�������쳣��\n"NOR;
                    ap=ap+random(ap);
                    }
                    
			msg += HIB "$N��֫һ�ڣ���Ӱ�ζ���ɲ�Ǽ�����$n��ǰ��˫�������ݳ�������$n����Ҫ����\n"NOR;
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				printf(HIC"ciwan_busy=%d\n"NOR,ciwan_busy);
		}

        if( random(ap+dp) < dp )
        {
                msg += HIG"$p��ɫ΢�䣬˫�ּ��գ��о����յıܿ���һ�С�\n" NOR;
	            me->start_busy(1 + random(1));

				me->delete_temp("pixie_performtime");

        }
        else
			if(!target->query_temp("pixie/cimu")
				&&random(target->query_temp("pixie_times/ciwan"))>1+random(10)
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p��ǰ�Ѽ������У��������з�����˫���ɾ����ã�������һ�С�\n" NOR;
				me->start_busy(1 + random(1));
				me->delete_temp("pixie_performtime");

				}
			else
			{
				if(target->query_temp("pixie/cimu"))
					{
					msg += HIR "\n$n֪����ǰ����������֪�����²��룬������ֻ������һʹ����Ȼ�����С�\n"NOR;	
					}
				else
					{
					msg += HIR"$p���һ���������в�֪����Ǻã���������һʹ����Ȼ�����С�\n" NOR; 
					}
					target->add_temp("apply/parry",  -parry_skill);
					target->set_temp("pixie/ciwan",1);
					target->set_temp("cannot_perform",1);
					target->set_temp("cannot_perform_msg","��˫��Ҫ�������У��޷�ʩ���⹦��");
					target->add_temp("pixie_times/ciwan",1 );
					target->add("eff_qi",-(random((int)me->query_skill("pixie-jian"))*4/3));
                    if( userp(me) )
					{
					target->set_temp("ciwan_power", parry_skill);
                    target->apply_condition("b_ciwan",1+(int)(ciwan_busy/15));
					
					}
					else
  	                me->start_call_out( (: call_other, __FILE__, "remove_effect", target, parry_skill :), ciwan_busy);


					set_perform(me,perform_name);
   				    me->set_temp("pixie_performtime",5);
					me->start_busy(1 + random(2));


			}
		}

					if(!me->query_temp("pixie_noop"))
					call_out("checking_pixieflg", 1, me, target);
					
					me->add("neili", -50);
					me->add("jingli", -50);
					message_vision(msg, me, target);
                  return 1;
}
void remove_effect(object target,int parry_skill)
{
		        if( !target ) return;
                        target->set_temp("apply/parry", 0);
			target->delete_temp("pixie/ciwan");
			target->delete_temp("pixie_times/ciwan");
			target->delete_temp("cannot_perform");
			target->delete_temp("cannot_perform_msg");

	        if(target->is_fighting() )
			{
			target->start_busy(1 + random(1));
			message_vision(HIG"$N�忪����Ѩ����˫���ж��𽥻ָ�������\n"NOR,target );
			}
}
			
