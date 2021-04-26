// Code of ShenZhou
// jingang.c �����ͨ

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
	int original, skill;

	if( objectp(target) && target != me ) 
		return notify_fail("��ֻ���ý����ͨ�������Լ���ս����\n");

	if( !me->is_fighting() ) 
		return notify_fail("�������ս���в���ʹ�ý����ͨ��\n");

	if( me->query_temp("weapon") )
		return notify_fail("��ֻ���ڿ���ʱʹ�ý����ͨ��\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչ�����ͨ��\n");

	if( me->query_skill("jingang-quan", 1) < 90 )
		return notify_fail("��Ľ��ȭ���δ�����޷�ʩչ�����ͨ��\n");

	if( me->query("max_neili") <= 600 )
		return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչ�����ͨ��\n");

	if( (int)me->query("neili") < 600  )
		return notify_fail("�������������\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("���Ѿ������˽����ͨ��\n");

	skill = me->query_skill("jingang-quan", 1);
	original = me->query_str();

	me->add("neili", -skill*2);
	me->receive_damage("jingli", skill);

	message_vision(
	HIY "\n$N˫�ֺ�ʮ���ɲ�Ǽ����ܵض�ɽҡ������¡¡���죡 $N�����ζ�Ȼ��������౶����һ���հ�����������\n\n" NOR, me);

	me->add_temp("apply/strength", original*3);

	me->set_temp("jingang", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original :), skill/6);
//	me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/strength", - 3*amount);

	me->delete_temp("jingang");

	tell_object(me, "�㻺������һ�������ջؽ����ͨ�������ָֻ���ԭ״��\n");
}
