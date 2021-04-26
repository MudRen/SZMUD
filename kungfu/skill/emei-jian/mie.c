// Code of ShenZhou
// mie.c ���𽣡�

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int dodge, parry, attack, sword, busy_time;

	weapon = me->query_temp("weapon");
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		weapon = me->query_temp("secondary_weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);
	if( (int)me->query_temp("miejue") )
                return notify_fail("���Ѿ�ʩչ������񽣡���\n");

	if( me->query_skill("emei-jian", 1) < 100 )
		return notify_fail("����ҽ�����Ϊ����������δ�����𽣡���\n");

	if( me->query_skill("linji-zhuang", 1) < 100 )
		return notify_fail("����ڹ���Ϊ���δ����ʩչ���𽣡�ֻ���˼�����\n");

	if( me->query_temp("perform/miejian") )
		return notify_fail("���������á��𽣡��ķ���\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���𽣡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽����������á��𽣡�����\n");

	if( me->query_skill_mapped("force") != "linji-zhuang" )
		return notify_fail("�����õ��ڹ��롸�𽣡��ķ���㣣�\n");

	if( me->query("max_neili") <= 1000 )
		return notify_fail("���������Ϊ���㣬����������ʩչ���𽣡���\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������������������ʩչ���𽣡���\n");

        if( me->query("jingli") <= 100 )
                return notify_fail("��ľ������ޣ�������ʩչ���𽣡���\n");

	if( userp(me) )
	{
		me->add("neili", -100);
		me->add("jingli", -30);
	}

	dodge = target->query_skill("dodge")/3;
	parry = target->query_skill("parry")/3;
	attack = sword = me->query_skill("sword")/5;
	me->add_temp("apply/sword", sword);

	if( target->query_temp("perform_target/miejian") )
	{ // the target is already being performed by mie

		message_vision(HIY "\n$Nһ����Х�������ڿ����������Ҿ������𽣡��ķ�"+
			"���뽣��֮�У�����"+weapon->name()+"�����������������Ƹ������죡\n"+
			"$n�����Ѿ��ۻ����ң�����֮�¸��ǲ�֪���룡\n" NOR, me, target);

		// 2/3 the length of tjj's chan, need two person to perform
		// but 100% succ rate !!
		busy_time = me->query_skill("emei-jian", 1) / 30;

		// if target was busy before, we shouldn't set him free
		busy_time += target->query_busy();  

		// there is always 1/3 time for the target to escape, unless there are 
		// 3 or more players perform mie on him with good synchronization.
		target->start_busy(busy_time);

		// make sure we can't perform continuously
		call_out("finish_mie2", sword/4, me, target, sword);
        }
	else if( me->query_temp("miejian/"+target->name()) )
	{
		message_vision(HIY "\n$Nһ����Х�������ڿ����������Ҿ������𽣡��ķ�"+
"���뽣��֮�У�����"+weapon->name()+"�����������������Ƹ������죡\n"+
			"$n������̹�������ȫ���ע��С�������\n" NOR, me, target);

		target->add_temp("apply/dodge", -dodge/3);
		target->add_temp("apply/parry", -parry/3);
		target->add_temp("apply/attack", -attack/3);
		target->add_temp("apply/speed", -dodge/30);
		call_out("remove_effect", sword/3, me, target, dodge/3, parry/3, attack/3, sword);
	}
	else
	{
		message_vision(HIY "\n$Nһ����Х�������ڿ����������Ҿ������𽣡��ķ�"+
"���뽣��֮�У�����"+weapon->name()+"�����������������Ƹ������죡\n"+
			"$n�ۻ����ң������˸����ֲ�����\n" NOR, me, target);
		target->add_temp("apply/dodge", -dodge);
		target->add_temp("apply/parry", -parry);
		target->add_temp("apply/attack", -sword);
		target->add_temp("apply/speed", -dodge/10);
		call_out("remove_effect", sword/2, me, target, dodge, parry, attack, sword);
	}

	me->set_temp("perform/miejian", 1);
	me->set_temp("miejian/"+target->name(), 1);

	// count of how many person perform mie on him
	target->add_temp("perform_target/miejian", 1);  

	return 1;
}

void remove_effect(object me, object victim, int dodge, int parry, int attack, int sword)
{
	if( objectp(victim) )
	{
		victim->add_temp("perform_target/miejian", -1);
		victim->add_temp("apply/dodge", dodge);
		victim->add_temp("apply/parry", parry);
		victim->add_temp("apply/attack", attack);
		victim->add_temp("apply/speed", dodge/10);
	}

	if( objectp(me) )
	{
		me->add_temp("apply/sword", -sword);
		me->delete_temp("perform/miejian");
	}

	if( objectp(me) && objectp(victim) && victim->is_fighting(me) )
		message_vision(HIY "\n\n$N������Ӧ��$n�Ľ�·������������ˡ�\n" NOR, victim, me);
}

void finish_mie2(object me, object victim, int sword)
{
	if( objectp(victim) )
		victim->add_temp("perform_target/miejian", -1);

	if( objectp(me) )
	{
		me->add_temp("apply/sword", -sword);
		me->delete_temp("perform/miejian");
	}

	if( objectp(me) && objectp(victim) && victim->is_fighting(me) )
		message_vision(HIY "\n$N������Ӧ��$n�Ľ�·������������ˡ�\n" NOR, victim, me);
}
