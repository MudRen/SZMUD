// Code of ShenZhou
// special drink.c
#include <dbase.h>
#include <ansi.h>

int exert(object me, object target)
{
	if (!wizardp(me))
            return notify_fail("�⹦�ܻ������š�\n");
	if (!target || !target->query("max_liquid") )
            return notify_fail("�ⲻ��װˮ��������\n");

	if (target->query("liquid/remaining") < 1 )
            return notify_fail(target->name()+"����ûʲô���Ժȵ��ˡ�\n");

	if( me->is_fighting() )
		return notify_fail("ս���к�ʲô������\n");

	if ((int)me->query_skill("zixia-gong", 1) < 40)
		return notify_fail("�����ϼ����Ϊ��������\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("�������������\n");

	if( me->query("water") >= me->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");


        message_vision(MAG "����$N�������Ϣ���ϸ�����������������������������������������ϼ��ʹ�ó����뻯���������\n" NOR, me, target);
        message_vision(HIW "$N��$n"+HIW"�յ����ϣ��ſڱ�ȣ�ֻ���ù�ཹ��ֱ�죬������������������ȡˮ����$n"+HIW"���"+target->query("liquid/name")+"�ȵõ�串�ʣ��\n" NOR, me, target);

	if( me->is_fighting() ) me->start_busy(2);


	me->add("water", 30 * target->query("liquid/remaining", 1));
	target->set("liquid/remaining", 0);
	if( target->query("liquid/drink_func") ) return 1;

	switch(target->query("liquid/type")) {
		case "alcohol":
			me->apply_condition("drunk",
				(int)me->query_condition("drunk") 
				+ (int)target->query("liquid/drunk_apply")
				+ (int)me->query("max_neili") / 25);
			break;
	}
	

	me->add("neili", -10*target->query("liquid/remaining", 1));
	me->start_busy(3);

	return 1;
}
