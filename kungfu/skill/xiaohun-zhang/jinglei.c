// Code by Scatter
// Chinese By Chchong
// ��Ȼ������
// xiaohun-zhang 2.2A

#include <ansi.h>

inherit F_SSERVER;

//Start from Here, Testing Perform Restriction
int perform(object me, object target)
{
  object ob;
  string msg;
  int damage;
  int finger, skill, jiali, my_rate, your_rate;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) )
	 return notify_fail("�ٲ�����ֻ����ս�����á�\n");

  if( me->query_temp("yield") )
	 return notify_fail("�㲻���֣����ʹ�ó��ٲ����ף�\n");

  if( (skill = (int)me->query_skill("yunu-xinjing", 1)) < 100 )
	 return notify_fail("�����Ů�ľ��˽ⲻ������, �޷�ʹ���ٲ����ס�\n");

  if( me->query_skill("strike") < 120 )
	 return notify_fail("�����Ȼ�����Ʋ�������, �޷�ʹ���ٲ����ס�\n");

  if( me->query_skill_mapped("force") != "yunu-xinjing" )
	 return notify_fail("�����õĲ�����Ů�ľ����޷�ʹ���ٲ����ף�\n");

  if( me->query("neili") < 300 ) return notify_fail("�������������㣬�޷�ʹ���ٲ����ס�\n");


//Start From Here,  Acture Perform Display


/*
[14] about pfm jinglei                        ����(chchong)(Fri Aug 10)
----------------------------------------------------------------------
����ʱ������! "ͻȻ$N��ɫ���,��ʽҲԽ������,��$n����һ��,
��Լ֮�䷢�����װ������,�Ʒ絽��ɰ��ʯ����Ȼ�羪���İ�,���ư�������ֻ���мܲ��ܶ���!"
��������! "$nͻȻ����$N��ʽͻ��,һ�ƹ����ؿڶ�ʱ��������,����֮�м���һ��,��ʱ�о���Ѫ��ӿ��˵����������!"
*/



//***** Perform Message *****
  msg = HIY "\nͻȻ$N��ɫ���,��ʽҲԽ������,��$n����һ�ơ�\n\n"NOR;
  msg += HIB"��Լ֮�䷢�����װ������,�Ʒ絽��ɰ��ʯ����Ȼ�羪���İ�,\n";
  msg += HIW"���ư�������ֻ���мܲ��ܶ���!\n";


//***** TESTING CONDITION *****
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 500) damage = 500;
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

//		msg += HIR"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
		if ( damage < 1000) {
			msg += HIC"ͻȻ֮��$n�о�һ�ɾ޴���Ʒ����Լ�Ϯ��,��æ����,������Ǳ��������ұ�,�����˼���!\n"NOR;
		}else if ( damage < 1500) {
			msg += HIR"ֻ��$N��ɫ��䷢��������һ��,���м����ź������֮��,գ��֮�������$n��С��,$n���в�֧������������ǿվס!\n"NOR;
		}else if ( damage < 2000) {
			msg += YEL"$n���ڲ����������ô������ƾ޴�,�ؿ��Ѿ���$N��������������,ֻ������Ѫ����,��������Ҫӿ������,;��ɫ�ɺ����,���ϱ�����������ס����!\n"NOR;
		}else if ( damage < 2500) {
			msg += RED"$nֻ����$N���ƺ�����һ���ĵ�$n�ؿ�,��ʱ$n�����Ƽ�������,��������������λ��,һ����Ѫ�������,��Ҳ������������!\n"NOR;
		}else if ( damage < 3000) {
			msg += RED"$N��Ӱ�ζ�,����㷢������һ��,$n��δ������ô�����ؿ��߹��ѱ����,��Ѫ����ǰ���˳���,����֮����������!\n"NOR;
		}else {
			msg += RED"��������Ȼһ�����죬$N�Ѵ�����$p�ؿ�.\n"NOR;
		}
		msg += NOR;
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 350) damage = 350;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIY"$N����һ��$n����������������,Ƭ��֮�令ס����,Ӳ�����Ľ���һ��,����$n��Ȼ���˲��ٵĿ�!\n\n"NOR;
		if ( damage < 400) {
			msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"ͻȻ֮��$n�о�һ�ɾ޴���Ʒ����Լ�Ϯ��,��æ����,������Ǳ��������ұ�,�����˼���!\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$nֻ����$N���ƺ�����һ���ĵ�$n�ؿ�,��ʱ$n�����Ƽ�������,��������������λ��,һ����Ѫ�������,��Ҳ������������!\n"NOR;
		}
		else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
	  random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIM"$N����һ��$n��֪�Լ��ѷǵ��֣�����֮���ѱ������ĵ���һ����Ѫ�����˳�����\n�ؿ��߹Ǵ��,����̱���ڵ��أ�\n\n"+NOR;
		if ( damage < 400) {
			msg += HIC"$n����һ�Σ����㲻����������Ҫˤ����\n"NOR;
		}else if ( damage < 600) {
			msg += HIR"$n������ˤ����������۵�һ�������һ����Ѫ��\n"NOR;
		}else if ( damage < 1000) {
			msg += RED"$n�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����ࡣ\n"NOR;
		}
		else msg += RED"$n���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磮\n"NOR;

		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIC"$n�����Ǳ��ıܿ�$N�����ٲ�����,������������ʽ�ų�һ����亹,\n\n"NOR;
	 msg += HIW"��������,���ڵ���,���ϱ��Ʒ�ε�֮��Ҳ�����˺�ӡ!\n" NOR;
	 me->add("neili", -300 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
