// Code of ShenZhou
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
        if( weapon->query("skill_type") != "sword" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����ġ�������\n");

/*        if( (string)weapon->query("id") != "xiuhua zhen" && 
            (string)weapon->query("id") != "qijue zhen" )
                 return notify_fail("��û�г��ֵı���������ʩչ�����ġ�������\n");
*/
        if( ( (int)me->query_skill("pixie-jian", 1)) < 180 )
                return notify_fail("��ı�а����������죬�޷�ʹ�������ġ���\n");

		if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ����ѽӽ����֡�\n");	
		
        //if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		perform_name="pixie-cixin";

		ap = me->query_skill("sword")/2;
		dp = target->query_skill("dodge")/2;
		
		if(random(me->query("dex")>15)||(random(me->query("int")>15)))
		{
			ap+=ap;
		}
		if(me->query("qi")<me->query("max_qi")/7)
			ap=ap*2;
		if(me->query("combat_exp")<(target->query("combat_exp")/3))
			ap=1;

		weapon = me->query_temp("weapon");
		msg="";

		//do super perform
		
		damage=me->query_skill("pixie-jian",1)*(random(5)+5);
		if(me->query_skill("pixie-jian",1)>400)
		damage=damage*2;
		if(!do_prepare_superskill(perform_name,me,target,ap,dp))
		
		{
                       if(!me) return;
		    if(target->query_temp("pixie/cimu"))
		 {
                        msg = HIW "\n��$n˫Ŀʧ��֮ʱ��$Nһ����Ц��ʹ����а���������ġ�֮����\n"NOR;
			ap=ap+random(ap);
			damage=damage+damage/5;
		}
			msg += HIB "$N��ҡ��֫����ӰƮ�����û�������������Ӱ��ͻȻһӰ�ɳ���Ϯ��$n��\n"NOR;
		if( wizardp(me) &&me->query("env/pixie_test"))
		{
				printf(HIC"ap=%d\tdp=%d\n"NOR,ap,dp);
				
		}

        if( random(ap+dp) < dp||(random(7)==0))
        {
                msg += HIG"$n���þ������棬֪����$Nʩչ����ɱ�ţ��Ͻ���ס���ƣ�һ��б�������յıܿ���һ�С�\n" NOR;
		                me->start_busy(2 + random(1));

				me->delete_temp("pixie_performtime");

        }
        else
			if(!target->query_temp("pixie/cixin")
				&&random(target->query_temp("pixie_times/cixin"))>1
				&&random(target->query_int())>random(me->query_int()))
				{
				msg += HIG"$p��ǰ�Ѽ������У��������з�����һ��б������Ȼ�����\n" NOR;
				me->start_busy(3 + random(1));
				me->delete_temp("pixie_performtime");

				}
			else
			{
         msg +=HIR"$nֻ����ǰ������������֪���²���������Ŀ�һ���ʹ���ѱ�$N���С�\n"NOR;
					//damage=me->query_skill("pixie-jian",1)*(random(5)+5);
					target->set_temp("pixie/cixin",1);
					target->add_temp("pixie_times/cixin",1 );
					target->add("eff_qi",-damage);
					target->add("qi",-damage);
					target->add("jingli",-damage/2);
					if(target->query("eff_qi")<=0)
					{
						target->set("eff_qi",0);
						target->unconcious();
					}
					if(target->query("qi")<=0)
						{
						target->set("qi",0);
						target->unconcious();
					}
			
					if(target->query("jingli")<=0)
						target->unconcious();
						
					set_perform(me,perform_name);
   				    me->start_busy(2 + random(1));


			}
		}
                                        if(!me->query_temp("pixie_noop") && target)
                                        call_out("checking_pixieflg", 1, me, target);
                                        
                                        me->add("neili", -100+random(200));
                                        me->add("jingli", -100+random(200));
										message_vision(msg, me, target);
                  return 1;
}
