// Code of ShenZhou
// qisuck.c

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

	if( objectp(me->query_temp("weapon")) && me->query_skill("huagong-dafa",1) < 45)
		return notify_fail("��Ļ����󷨹���������������ֲ���ʩ�û���������������\n");

	if( !me->is_fighting() || !target->is_fighting() || !living(target) )
		return notify_fail("�������ս���в�����ȡ�Է���������\n");

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("qi") < (int)target->query("max_qi") / 5
	 || (int)target->query("jingli") < (int)target->query("max_jingli") / 5 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");

	message_vision(
		HIB "$NͻȻ�����һЦ��˫��һ�Ĵָ��׼$n�����İ��˹�����\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
	dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
		  sp *= me->query("combat_exp")/1000;
		  dp *= target->query("combat_exp")/1000;

	me->set_temp("sucked", 1);

	if( random(sp+dp) > dp )
	{
		tell_object(target, HIR "��ͻȻ����ȫ�����������Ʊ�ӿ��������֫��������Ҳʹ����������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);
		message_vision(
			HIR "$N����ȫ�����������Ʊ�ӿ��������֫��������Ҳʹ����������\n\n" NOR,
			target );

		me->add("qi", (int)me->query_skill("force") );

		if( target->query("combat_exp") >= me->query("combat_exp")/2 )
			me->add("combat_exp",1);

		me->start_busy(random(2));
		target->start_busy(random(2));
		me->add("neili", -(int)me->query_skill("force")/6);
		me->add("jingli", -5);

		dmg = random( me->query_skill("force")/100 )* me->query("neili");
		if( dmg > 2000) dmg=2000;
		if( dmg <300) dmg=300;
		dmg = random(dmg);
		target->receive_damage("qi", dmg, me );
		target->receive_wound("qi", random(dmg), me);

		COMBAT_D->report_status(target);

		call_out("del_sucked", 1, me);
	}
	else
	{
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->add("jingli", -5);
		me->start_busy(2);
		call_out("del_sucked", 1+random(2), me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
