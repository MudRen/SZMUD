// Code of ShenZhou
// pojian.c ���¾Ž����ܾ�ʽ��
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
		return notify_fail("�ܾ�ʽֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 100 || (int)me->query("max_neili") < 500 )
		return notify_fail("��Ķ��¾Ž���������Ϊ��������δѧ�ɡ��ܾ�ʽ����\n");

        if( me->query("neili") <= 100 )
                return notify_fail("�������������\n");

	msg = CYN "$N����$n��ʽ��������ʹ�����¾Ž����ܾ�ʽ��������һ����ߺ���\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
	    if( !weapon = target->query_temp("weapon") ) {
             switch (random(2)) {
             case 0:
		msg += "$p����֮�࣬�����޴ӣ������������������ˡ�\n" NOR; 
		target->add("eff_qi",-(random((int)me->query_skill("dugu-jiujian"))*2));
		break;
	     case 1:
		msg += "$p����Ī�������ܲ��ܣ���$P���е����������\n" NOR;
		target->add("neili",-(random((int)me->query_skill("dugu-jiujian"))*2));
		break;
	     }
	    }
	    else {
             switch (random(2)) {
             case 0:
		msg += "$pĪ�������˼����Ϊ��$P����һ������������ֻ�÷���"+weapon->query("name")+"��\n" NOR;
		weapon->move(environment(me));
                break;
             case 1:
                msg += "$p����Ī�������ܲ��ܣ���$P���е����������\n" NOR;
                target->add("neili",-(random((int)me->query_skill("dugu-jiujian"))*2));
                break;
             }
	    }
	    target->start_busy( (int)me->query_skill("sword") / 28 );
	} 
	else {
		msg += "$p��Ȼ������$P�Ľ�·���������ѷ��ܻ��е�����\n" NOR;
		me->start_busy(1 + random(3));
	}
	message_vision(msg, me, target);
	me->add("neili", -25);
	me->add("jingli", -10);

	return 1;
}
