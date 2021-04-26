// Code of ShenZhou
// pojian.c ���¾Ž�������ʽ��
// qfy July 5, 1996.

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ʽֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip" )
		return notify_fail("����ʽֻ�ܶ��ó��ޡ������Ķ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 60 )
		return notify_fail("��Ķ��¾Ž���Ϊ��������δѧ�ɡ�����ʽ����\n");

        if( me->query("neili") <= 100 )
                return notify_fail("�������������\n");

	msg = CYN "$N����ͻȻ����������ǧ���ͼ�Զ��¾Ž��ġ�����ʽ����ס$n��"+weapon->query("name")+"��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��"+weapon->query("name")+"��$P�Ľ������������ַɳ���\n" NOR;
		weapon->move(environment(me));
		target->start_busy( (int)me->query_skill("sword") / 28 );
	} else {
		msg += "����$p������$P�Ľ�·�����е�����\n" NOR;
		me->start_busy(1 + random(3));
	}
	message_vision(msg, me, target);
	me->add("neili", -25);
	me->add("jingli", -10);

	return 1;
}
