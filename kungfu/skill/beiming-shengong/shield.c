// shield.c ��ڤ�񹦻�����
// modified by xuanyuan to add restrict eunuch use force 10/31/2001

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("��ֻ���ñ�ڤ�������������Լ��ķ�������\n");

	if( (int)me->query("neili") < 1000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("beiming-shengong",1) < 100 ) 
		return notify_fail("��ı�ڤ����Ϊ������\n");

	if ( me->query("gender") == "����" )
		return notify_fail("���޸����ԣ������������������ñ�ڤ�����񹦡�\n");

	if( (int)me->query_temp("shield") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -(1000-(int)me->query_skill("beiming-shengong",1)));
	me->receive_damage("qi", 0);

	message_vision(
	HIW "$N˫��ƽ�ٹ���������ڤ�����񹦣�ȫ�������ھ���֮�У�\n" NOR, me);

	me->add_temp("apply/armor", skill*2);
//	me->add_temp("apply/defense",  skill*2);
	me->set_temp("shield", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/armor", - amount);
//	me->add_temp("apply/defense", - amount);
	me->delete_temp("shield");
	tell_object(me, "��ı�ڤ������������ϣ��������ջص��\n");
}
