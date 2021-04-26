// Code of ShenZhou
// neilisuck.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;
	int dmg;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || target == me
	|| target->query("id") == "mu ren"
	|| target->query("id") == "shangshan"
	|| target->query("id") == "mengzhu"
	|| target->query("id") == "fae" )
		return notify_fail("��Ҫ��ȡ˭��������\n");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( objectp(me->query_temp("weapon")) && me->query_skill("huagong-dafa",1) < 90)
		return notify_fail("��Ļ����󷨹���������������ֲ���ʩ�û���������������\n");

	if( !me->is_fighting() || !target->is_fighting() || !living(target) )
		return notify_fail("�������ս���в�����ȡ�Է���������\n");

	if( (int)me->query_skill("huagong-dafa",1) < 60 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)me->query("neili") >= (int)me->query("max_neili") * 2 )
		return notify_fail("����ȡ����������ȫ���޷�����ȡ������\n");

	if( (int)target->query("max_neili") <= 1 )
		return notify_fail( target->name() +
			"û���κ�������\n");

	if( (int)target->query("neili") < (int)target->query("max_neili") / 10
	 || (int)target->query("jingli") < (int)target->query("max_jingli") / 5 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");

	message_vision(
		HIW "$Nһ����ͻȻ��òҰף�����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
	dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
		  sp *= me->query("combat_exp")/1000;
		  dp *= target->query("combat_exp")/1000;

	me->set_temp("sucked", 1);

	if( random(sp+dp) > dp )
	{
		message_vision(
			HIR "$N�پ�����΢ʹ����ͬ��������˸�С�ף�ȫ��������ˮ����ѭ�׷�й������\n\n" NOR,
			target );

		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);

		if ((int)target->query("neili") > (int)me->query_skill("force"))
		{
			target->add("neili", -1*(int)me->query_skill("force") );
			me->add("neili", 2*((int)me->query_skill("force")));
		}else{
			me->add("neili", 2*(int)target->query("neili"));
			target->set("neili", 0);
		}
		
		if( target->query("combat_exp") >= me->query("combat_exp")/2 ) {
			me->add("potential", 1);
			me->add("combat_exp", 1);
		if (me->query("potential") > me->query("max_potential"))
					 me->set("potential", me->query("max_potential"));
		}

		me->start_busy(1+random(3));
		target->start_busy(1+random(3));
		me->add("neili", -(int)me->query_skill("force")/7 );
		me->add("jingli", -5);

		COMBAT_D->report_status(target);

		call_out("del_sucked", 1+random(2), me);
	}
	else
	{
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->add("jingli", -5);
		me->start_busy(1 + random(3) );
		call_out("del_sucked", 1+random(3), me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}

