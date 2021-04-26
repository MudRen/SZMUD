// Code of ShenZhou
// hebi.c ȫ�潣֮����Ů�����
//by sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object victim, int amount);
private int remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object victim;
	object weapon;

	if( !victim ) victim = offensive_target(me);

	if( !victim || !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target )
                return notify_fail("������˭����˫����赣�\n");

	if( victim->query("id") == target->query("id") )
		return notify_fail("��������˽���˫����赣�\n");

	if( !target->is_fighting(victim) )
		return notify_fail("��������˫����赵Ķ���δ����ĵ��˲�����\n");

	if( target->query_skill_mapped("sword") != "yunu-jianfa" )
		return notify_fail("��������˫����赵Ķ�����ʹ�õĲ�����Ů������\n");

	if(!objectp(weapon = target->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("��������˫����赵Ķ���û���ý���\n");
	
	if( (int)me->query_temp("hebi") ) 
	{
		return notify_fail("������"+target->name()+"����˫����赡�\n");
	}

	if( (int)target->query_temp("hebi") ) 
                return notify_fail("��������˫����赵Ķ����������˺ͱ�ս���У���Ͼ�����赣�\n");


	skill1 = me->query_skill("sword");
	skill2 = target->query_skill("sword");
	skill =  ( skill1 + skill2 ) / 4; 

	message_vision(
	HIR "\n$N��$nͻȻ��˫��һ����ȫ�潣������Ů������ϵ������޷죬���Ƽ�������Ȼ������\n\n" NOR, me, target);

	me->add_temp("apply/attack", skill/6);
	me->add_temp("apply/damage", skill/6);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->set_temp("hebi", 1);

    me->add_temp("apply/damage", 180);
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->add_temp("apply/damage", -180);
	me->add("neili", -150);


	target->add_temp("apply/attack", skill/6);
	target->add_temp("apply/damage", skill/6);
	target->add_temp("apply/parry",  skill/2);
	target->add_temp("apply/dodge",  skill/2);
	target->set_temp("hebi", 1);
    target->add_temp("apply/damage", 180);
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
    target->add_temp("apply/damage", -180);
	target->add("neili", -150);


	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill/2 :), 1);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;
	if( !me->query_temp("hebi") || !target->query_temp("hebi") ) return;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ||
		victim->query("qi") <= 50 && me->is_fighting(victim) && target->is_fighting(victim) ) 
	{
		remove_effect(me, amount);
        remove_effect(target, amount);
		message_vision(HIY"$N��$n�������У�����һЦ��\n\n"NOR, me, target);
				return;
	}
	else if( (!present(victim->query("id"), environment(me)) && target->is_fighting(victim)) 
	|| (!present(target->query("id"), environment(me)) && me->is_fighting(victim)) ) {
		remove_effect(me, amount);
        remove_effect(target, amount);
		tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
        tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
        tell_object(victim, HIY"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
				return;
	}
 	else if( !present(target->query("id"), environment(me)) 
	|| !target->is_fighting() || !me->is_fighting() || !living(target)
	|| !living(me) || target->is_ghost() || me->is_ghost() ) {
		remove_effect(me, amount);
        remove_effect(target, amount);
		tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
		tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
		tell_object(victim, HIY"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
				return;
	}
	else if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "sword" ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, HIY"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
				return;
	}
	else if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" ) {
                remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(target, HIR"˫�������Ȼ�߽⣡\n"NOR);
                tell_object(victim, HIY"˫�������Ȼ�߽⣬ѹ���ټ����㲻��Ȼ������һ������\n"NOR);
				return;
        }

	call_out("check_fight", 1, me, target, victim, amount);
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount/3);
	me->add_temp("apply/damage", -amount/3);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->delete_temp("hebi");

	return 0;
}
