// Code of ShenZhou
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 40 )
		return notify_fail("��Ļ���������Ϊ������\n");

	if( target->query("id") == me->query("id") )
		return notify_fail("�㲻��Ϊ�Լ����ˣ�\n");

	if( !living(target) )
                return notify_fail("̫���ˣ���Ҫ���Ƶ����Ѿ����ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIY "$N�����ڹ������ư���$n�������ţ�����������$n����....\n"
		"���ã�$N��������죬�Ե�ʮ��ƣ�롣\n"
                "ֻ��$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->add("qi", -50);
	me->set("jiali", 0);

	return 1;
}
