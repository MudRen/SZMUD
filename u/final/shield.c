// Code of ShenZhou
// shield.c ������

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("��ֻ����������������˻����񹦡�\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("shielded") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

        if( (int)me->query_temp("longxiang") )
                return notify_fail("���Ѿ���������֮���ˡ�\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 40)
		return notify_fail("������������������\n");

	skill = me->query_skill("longxiang-banruo");
	me->add("neili", -200);

	message_vision(
	MAG "$N����һ�������������񹦣�����������������һ����������ȫ��\n" NOR, me);

	me->add_temp("apply/armor",  skill);
	me->add_temp("apply/defense",  skill);
	//me->add_temp("apply/armor_vs_force", skill/2)

	me->set_temp("shielded", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/2);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	//me->add_temp("apply/armor_vs_force", - amount)
	me->add_temp("apply/armor", - amount);
	me->add_temp("apply/defense", - amount);
	me->delete_temp("shielded");
	tell_object(me, "��Ļ�����������ϣ��������ջص��\n");
}

