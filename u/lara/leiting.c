// Code of ShenZhou
// leiting ��������
// Lara 2001/11/11
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
	string weapon;
	int skill, enfor, amount;

	enfor = me->query("jiali");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ֻ�ܿ������á�\n");

	if( me->query_str() < 30 )
		return notify_fail("��ı���������ʩչ����������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("�����õĲ��ǻ����������޷�����ʩչ����������\n");

	if( me->query_skill("force") < 135 )
		return notify_fail("��Ļ����������δ�����޷�ʩչ����������\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("�㽵��ʮ������Ϊ���㣬������ʹ������������\n");

	if( (me->query("neili") - (150+enfor+enfor/2)) <= 350 )
		return notify_fail("�����������ʹ������������\n");

        if( me->query_temp("xianglong",1) )
                return notify_fail("������ʹ���ڹ����޷���������������\n");

	if( me->query_temp("sanhui_busy") )
		return notify_fail("��΢һ�˾���ֻ��������Ϣ���ǣ��������ƣ�\n");

	if ( me->query_condition("hyz_damage") )
		return notify_fail("�����ܻ�Ԫ�����ˣ��᲻������ʩչ����������\n");

	message_vision(HIR "\n$N�����ȣ�˫������������ض���$n�������Ʒ��������ɰ��ʯ�����Ϊ֮��ɫ��\n\n" NOR, me, target);

	skill = me->query_skill("force");
	amount = skill/2;

	me->add_temp("apply/attack", amount);
	me->add_temp("apply/strike", amount/2);
	me->add_temp("apply/damage", amount);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -amount*3);
	me->add("jingli", -amount);

	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/strike", -amount/2);

	me->start_busy(1+random(2));
	return 1;
}
