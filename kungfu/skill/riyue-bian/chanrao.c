// Code of ShenZhou
// chanrao.c �������

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
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	weapon = me->query_temp("weapon");
        if( weapon->query("skill_type") != "whip" )
                return notify_fail("�������ޱޣ����ʹ��������ƣ�\n");
	if( me->query("neili") <= 300 )
                return notify_fail("�������������\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$Nʹ�����±޷���������ƾ����������ޣ���������ŵ���$n��ȫ���ȥ��\n";

	me->add("neili", -100);
	me->add("jingli", -50);

	if( random(me->query("combat_exp")) > random(target->query("combat_exp")) ) 
	{
		msg += "���$p��$P���˸����ֲ��������������Ӱ�������У�\n" NOR;
		target->start_busy( (int)me->query_skill("whip") / 30 );
	} 
	else 
	{
		msg += "����$p������$P�ı޷�ȥ·�����ݵ����˿�ȥ��\n" NOR;
		me->start_busy(1 + random(3));
	}

	message_vision(msg, me, target);

	return 1;
}
