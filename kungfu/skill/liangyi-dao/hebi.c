// Code of ShenZhou
// hebi.c �����ǵ���֮˫�����
// by qfy
// fixed hebi with self and remain dodge after hebi problem, sdong, 07/22/98
// if one player quit, the other will be able to keep the effect. This got fixed now, sdong, 2/9/2000

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object victim, int amount);
private int remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object victim,weapon;

	if( !victim ) victim = offensive_target(me);

	if( !victim || !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target )
                return notify_fail("������˭����˫����赣�\n");

	if( victim->query("id") == target->query("id") )
		return notify_fail("��������˽���˫����赣�\n");

	if( target->query("id") == me->query("id") )
		return notify_fail("�Լ�����Լ�����ϧ�㲻�����һ�����\n");

	if( !target->is_fighting(victim) )
		return notify_fail("��������˫����赵Ķ���δ����ĵ��˲�����\n");

	if( target->query_skill_mapped("blade") != "liangyi-dao" )
		return notify_fail("��������˫����赵Ķ�����ʹ�õĲ��Ƿ����ǵ�����\n");

	if( (int)target->query_temp("hebi") ) 
                return notify_fail("��������˫����赵Ķ����������˺ͱ�ս���У���Ͼ�����赣�\n");

	if(!objectp(weapon = target->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("��������˫����赵Ķ���û���õ���\n");

	if( (int)me->query_temp("hebi") ) 
		return notify_fail("������"+target->name()+"���з����ǵ���˫����赡�\n");

	skill1 = me->query_skill("blade");
	skill2 = target->query_skill("blade");
	skill = ( skill + skill2 ) *3/2;

	message_vision(
	HIR "$N��$nͻȻ��˫��һ�������Ƽ������Ȼ��ʢ����ϵ������޷죡\n" NOR, me, target);

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge",  skill/2);
	me->set_temp("hebi", 1);
	target->add_temp("apply/attack", skill/2);
	target->add_temp("apply/dodge",  skill/2);
	target->set_temp("hebi_power", skill/2);
	target->set_temp("hebi", 1);
	target->apply_condition("liangyi_check", 1);

	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill/2 :), 1);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;
	if( !me || !objectp(me) )
	{
                remove_effect(target, amount);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ����
��һ������\n"NOR);
	    return;
	}
        if( !target || !objectp(target) )
        {
                remove_effect(me, amount);
                tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(me, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ����
��һ������\n"NOR);
            return;
        }

	
	if( !me->query_temp("hebi") || !target->query_temp("hebi") ) return;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ||
		victim->query("qi") <= 50 && me->is_fighting(victim) && target->is_fighting(victim) ) 
	{
		remove_effect(me, amount);
        remove_effect(target, amount);
		message_vision(HIG"$N��$n�������У�����һЦ��\n\n"NOR, me, target);
				return;
	}
	else if( (!present(victim->query("id"), environment(me)) && target->is_fighting(victim)) 
	|| (!present(target->query("id"), environment(me)) && me->is_fighting(victim)) ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
		tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
	}
 	else if( !present(target->query("id"), environment(me)) 
	|| !target->is_fighting() || !me->is_fighting() || !living(target)
	|| !living(me) || target->is_ghost() || me->is_ghost() ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
		tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
		tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
		tell_object(victim, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
	}
	else if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "blade" ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
	}
	else if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade" ) {
                remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, GRN"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
    }

	call_out("check_fight", 1, me, target, victim, amount);
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
	me->delete_temp("hebi");
	me->delete_temp("hebi_power");

	return 0;
}
