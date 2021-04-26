// Code of ShenZhou
// chanshen.c ����
//wzfeng 2000 6

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("xiaoyaoyou", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
	  if( !target ) target = offensive_target(me);
	   if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���������֮��ֻ����ս���жԵ���ʹ�á�\n");

        if( (int)target->query_temp("gb_chanshen") )
                return notify_fail("�Է��Ѿ�����ʹ�������ס�ˣ�\n");
      if( (int)me->query_skill("xiaoyaoyou",1) < 150 )
      return notify_fail("�����ң�β�����죬����ʹ���������\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 150 )
      return notify_fail("�����ң�β�����죬����ʹ���������\n");
      if( (int)me->query_skill("huntian-qigong", 1) < 150 )
      return notify_fail("��Ļ��������ȼ�����������ʹ���������\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("�������̫��������ʹ���������\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("�������̫���ˣ�����ʹ���������\n");   
	        if( (int)me->query("neili") < 300 )
      return notify_fail("��ľ���̫���ˣ�����ʹ���������\n");   

			if(!me->query_temp("gb_huixuan"))
				return notify_fail("��û��ʹ����ң���������޷�ʹ���������\n");   


      message_vision(HIB"\nͻȻ��$N���з�����˻˻����������˫�ְ�������ָ��������״���������ң������ͻȻ�۽�$n����ߣ���$n���һ����\n"NOR, me,target);
      me->add("neili", -100+random(50)); 
      me->add("jingli", -50+random(50));      
	  	target->add_temp("apply/parry",  -lvl/3);
		target->add_temp("apply/dodge",  -lvl/3);
		target->add_temp("apply/aromr",  -lvl/3);
		if(target->query("combat_exp")<random(me->query("combat_exp"))*2
			)
		{
			message_vision(HIB"����$N������������Ы����һ�㣬����$n����ߣ���$n��֪���룬ֻ���ķ·������ε�����������������$n��\n"NOR, me,target);
			
			target->start_busy(3+random(lvl/40));
		}

		target->set_temp("gb_chanshen",1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", target, lvl/3 :), lvl/25);
		
		me->start_busy(1+random(1));
      return 1;
}

void remove_effect(object target,int lvl)
{
		        if( !target ) return;
			target->add_temp("apply/parry",  lvl);
			target->add_temp("apply/dodge",  lvl);
			target->add_temp("apply/aromr",  lvl);
			target->delete_temp("gb_chanshen");
	        if(target->is_fighting() )
			{
			target->start_busy(1 + random(1));
			message_vision(HIG"$Nʹ������������������������ε��ֵĹ�����С�\n"NOR, target);
			}
}

