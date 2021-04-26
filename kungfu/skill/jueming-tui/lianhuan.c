// Code of ShenZhou
//lianhuan.c ���� perform

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	mapping fam;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return notify_fail("��������̵��ӣ������˱��������ȷ���\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ����ͷת�򣬳˻������ɢ�\n");

	if( me->query_skill_mapped("strike") != "huagu-mianzhang" )
		return notify_fail("�����õĲ��ǻ������ƣ�������������������ʩչ��\n");

	if( me->query_skill_prepared("strike") != "huagu-mianzhang" )
                return notify_fail("�������Ĳ��ǻ������ƣ�������������������ʩչ��\n");

	if( me->query_skill("dulong-dafa", 1) < 60 )
		return notify_fail("��Ķ����󷨻��δ�����޷�ʩչ��������\n");

	if( me->query_skill("kick", 1) <40)
		return notify_fail("��������Ҫ��տ�Ļ����ȷ���ϣ�������Чʩչ��\n");

	if( me->query_skill("jueming-tui",1 ) <40)
		return notify_fail("���������Ϊ���㣬������ʹ����������\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ����������\n");

	if( (int)me->query("jingli") < 150 )
		return notify_fail("��ľ����޷����С�\n");

	msg = HIY "\n ͻȻ��$N�����ڿն��������$n�������߼��ȣ�\n" NOR;


	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") ) {

		target->start_busy( (int)me->query_skill("jueming-tui", 1) / 20 );
		damage = (int)me->query_skill("dulong-dafa", 1);
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		me->add("neili", -damage/10);

		if( damage < 40 ) msg += HIY"���$n��$N���������ߵ���ͷת�򣡢�\n" NOR;
		else msg += HIR"���$n��$N������������Ҫ�������ۣ�����һ����Ѫ��ӿ������\n"NOR;
	}

	 else {
		msg += "����$p������$P����ͼ������ö��˿�ȥ��\n" NOR;
		me->start_busy(1 + random(3));
	}
	message_vision(msg, me, target);

	return 1;
}

