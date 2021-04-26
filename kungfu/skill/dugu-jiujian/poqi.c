// Code of ShenZhou
// pojian.c ���¾Ž�������ʽ��
// qfy July 5, 1996.

#include <ansi.h>
private int qi_damage_300(object me, object target);
private int qi_damage_220(object me, object target);
private int qi_damage_150(object me, object target);

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int dugu_skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ʽֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 90 || (int)me->query("max_neili") < 400 )
		return notify_fail("��Ķ��¾Ž���������Ϊ��������δѧ�ɡ�����ʽ����\n");

        if( me->query("neili") <= 100 )
                return notify_fail("�������������\n");

	dugu_skill = me->query_skill("dugu-jiujian",1);

	msg = CYN "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ��$n�ĵ��\n";
	message_vision(msg, me, target);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {

		if ( dugu_skill >= 150 ) {
                        qi_damage_150(me, target);
                }

		if ( dugu_skill >= 220 && me->query("dugu/poqi") ) {
			qi_damage_220(me, target);
		}

		if ( dugu_skill >= 300 && me->query("dugu/poqi") ) {
			qi_damage_300(me, target);
		}

		target->start_busy( (int)me->query_skill("sword") / 28 );

	} else {
		msg = "����$p������$P�Ľ�·�����е�����\n" NOR;
		me->start_busy(1 + random(3));
		message_vision(msg, me, target);
	}

	me->add("neili", -25);
	me->add("jingli", -10);

	return 1;
}

#include "/kungfu/skill/dugu-jiujian/poqi.h"
