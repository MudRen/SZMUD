// Code of ShenZhou
// cimu.c ��а���������㡹֮��
// wzfeng@XKX 99 9 
// by snowyu fix ciwan add dodge BUG 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "pixie_superskill.c"
void remove_effect(object target,int dodge_skill);
int perform(object me, object target)
{
        string msg,perform_name;
		
        object weapon;
		
        int  ap, dp,cizu_busy,dodge_skill;
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����㡹֮��ֻ����ս���жԵ���ʹ�á�\n");
		if(!living(target))
			return notify_fail("�Ը����Ե��˻��衸���㡹?\n");


        if( (int)target->query_temp("pixie/cizu") )
                return notify_fail(target->name() +"�ѱ������˫��Ҫ����\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 300 )
                return notify_fail("��ľ���������\n");


        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("������Ρ����㡹����\n");

/*        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����㡹������\n");
*/
        if( weapon->query("skill_type") != "sword" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����㡹������\n");

        if( ( (int)me->query_skill("pixie-jian", 1)) < 100 )
                return notify_fail("��ı�а����������죬�޷�ʹ�������㡹������\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ����ѽӽ����֡�\n");	
		
        //if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-cizu";
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
		dodge_skill=target->query_skill("dodge");
		if(dodge_skill<=0)
			dodge_skill=0;
		
		//�������ĸߵ������������ʱ�䡣
		if(me->query("dex")>22&&me->query("dex")>target->query("dex"))
			cizu_busy=me->query_dex();
		else
			cizu_busy=me->query_dex()/2;

		//do super perform
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		{
		    if(target->query_temp("pixie/cimu"))
		 {
			msg = HIB "\n��$n˫Ŀʧ��֮ʱ��$Nһ����Ц��ʹ����а���������㡹֮����\n"NOR;
			ap=ap+random(ap);
		}
			if(me->query_temp("pixie/guimei") >0 )
                    {
                    msg += HIB "$N����Ӱ�������һ�㣬ɲ�Ǽ�������쳣��\n"NOR;
                    ap=ap+random(ap);
                    }
                  if(!me) return;
		msg += HIB "$NͻȻһ������գ�ۼ�Ʈ��$n��ǰ������"+weapon->query("name")+"����$n˫��ҪѨ��\n"NOR;

		
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				printf(HIC"cizu_busy=%d\n"NOR,cizu_busy);
		}

        if( random(ap+dp) < dp )
        {
				msg += HIG "$n�����춯��֪��$Nʩչ���У�æ���������Ծ�𣬽���һ����������Զ����\n"NOR;	
	            me->start_busy(1 + random(1));
   					me->delete_temp("pixie_performtime");
        }
        else
			if(!target->query_temp("pixie/cimu")
				&&random(target->query_temp("pixie_times/cizu"))>1+random(10)
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p��ǰ�Ѽ������У��������з�������������ˣ��ܿ���һ�С�\n" NOR;
				me->start_busy(1 + random(1));
				me->delete_temp("pixie_performtime");
				}
			else
			{
    msg += HIR "$nֻ����ǰ����������֪�����²��������ֻ��˫��һ�飬��������ʧȥ֪����\n"NOR;     
					target->add_temp("apply/dodge",  -dodge_skill);
					target->set_temp("pixie/cizu",1);
					target->set_temp("cannot_move",1);
					target->set_temp("cannot_move_msg","��˫��ҪѨ�����У����ﻹ���ƶ��벽��");
					target->add_temp("pixie_times/cizu",1 );
					target->add("eff_qi",-(random((int)me->query_skill("pixie-jian"))*4/3));
					       if( userp(me) )
					{
					target->set_temp("cizu_power", dodge_skill);
                    target->apply_condition("b_cizu",1+(int)(cizu_busy/15));
					
					}
					else
  	                	me->start_call_out( (: call_other, __FILE__, "remove_effect", target, dodge_skill :), cizu_busy);

					set_perform(me,perform_name);
   				    me->set_temp("pixie_performtime",5);

			//		me->start_call_out( (: call_other, __FILE__, "remove_effect", target, dodge_skill :), cizu_busy);
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
void remove_effect(object target,int dodge_skill)
{
		        if( !target ) return;
                        target->set_temp("apply/dodge", 0);
			target->delete_temp("pixie/cizu");
			target->delete_temp("pixie_times/cizu");
			target->delete_temp("cannot_move");
			target->delete_temp("cannot_move_msg");

	        if(target->is_fighting())
			message_vision(HIG"$N���ڳ忪����Ѩ����˫���ж��ָ�������\n");
			return;
}
