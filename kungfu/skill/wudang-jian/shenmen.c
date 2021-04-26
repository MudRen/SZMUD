// Code of ShenZhou
// shenmen.c ������ʮ������
// xQin 1/99

/*
ԭ���⡰����ʮ����������һʮ����������ÿ����ʽ������ͬ��������֮����
ȫ�ǵ�������ġ�����Ѩ����
*/

#include <combat.h>
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        mapping prepare;
        string msg, result;
        string attack_skill, dodge_skill, parry_skill;
        int ap, dp, pp, damage, level;
	object weapon, weapon2;

	if( !target ) target = offensive_target(me);

	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("������ʮ������ֻ����ս����ʹ�á�\n");

        if( !living(target) )
                return notify_fail("�����ڲ���ʹ�á�����ʮ��������\n");

	if( !me->query("wudang/shenmen") )
		return notify_fail("����δѧ�ᡸ����ʮ��������\n");

	if( !objectp(weapon = me->query_temp("weapon"))
		|| weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽�������ʹ��������ʮ����������\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻���������ʹ��������ʮ��������\n");

	if( me->query_skill_mapped("force") != "taiji-shengong")
		return notify_fail("�����õ��ڹ��롸����ʮ�������ķ���㣣�\n");

	if( me->query_skill("sword") < 120 )
		return notify_fail("��Ľ�����Ϊ������������ʩչ������ʮ��������\n");

	if( me->query("neili") <= 200 )
		return notify_fail("�����������������ʩչ������ʮ��������\n");

	if( me->query("jingli") <= 100 )
		return notify_fail("����������ޣ�����ʩչ������ʮ��������\n");

	msg = "\n$N�˽�����Ƶ磬ָ�ⶶ����$w�˲Ϣ֮�����ʮ���£�ʮ���㺮���ƺ�ͬʱ�˳���"
		"��㲻ʧ�����ÿһ��������$n��������Ѩ��\n"NOR;

	ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( target->is_busy() ) dp /= 3;
	if( dp < 1 ) dp = 1;

	if( random(ap + dp) < dp )
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg();
	}
	else
	{
		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( target->is_busy() ) pp /= 2;
		if( pp < 1 ) pp = 1;

		weapon2 = target->query_temp("weapon");
		if( random(ap + pp) < pp )
		{
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
				parry_skill = "parry";
			msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
		}
		else 
		{
			if( objectp(weapon2) )
			{
				msg += HIR"$nֻ���á�����Ѩ����һ�����飬��ָ������"
				"$W"HIR"�����ȣ����ڵ��£�\n"NOR;                        
				weapon2->unequip();
				weapon2->move(environment(target));
			}
			else
			msg += HIR"$nֻ���á�����Ѩ����һ�����飬$W��Ҳʹ�������������\n"NOR;

			level = me->query_skill("wudang-jian", 1);
			target->reset_action();
			target->start_busy(1+random(level/100));

			damage = 10+random(29);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me);

			result = COMBAT_D->damage_msg(damage, "����");
			msg += result;

			result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
				(int)target->query("max_qi"));
			msg += "( $n"+result+" )\n";
		}
	}

	me->add("neili", -100);
	me->add("jingli", -50);
	me->start_busy(1);

	msg = replace_string( msg, "$l", "����Ѩ" );
	msg = replace_string( msg, "$w", weapon->name() );

	prepare = target->query_skill_prepare();
	if( !prepare ) prepare = ([]);

	switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[random(2)]; break;
	}

        if( objectp(weapon2) )
		msg = replace_string( msg, "$W", weapon2->name() );
	else switch( attack_skill )
	{
		case "finger" :	msg = replace_string( msg, "$W", "��ָ" );
				break;
		case "cuff" :	msg = replace_string( msg, "$W", "ȭͷ" );
				break;
		case "strike" :	msg = replace_string( msg, "$W", "����" );
				break;
		case "claw" :	msg = replace_string( msg, "$W", "��צ" );
				break;
		default :	msg = replace_string( msg, "$W", "" );
				break;
	}

        message_vision(msg, me, target);
        return 1;
}
