// Code of Shenzhou
// creat by Karlopex@sz
/*************************************************************************************
perform wuji ���������޼�����--�и����ڳ���֮ͨǰһ����Ҫ������pfm�����ٹ���һ�У������޴󣬵���������ͬ���޴�
����������ȭ�ȼ�200�����칦�ȼ�200����ע��������Ч�ȼ���
���ܣ�����20% attack
���ƣ�ֻ����pfm sanhua ���� perform yanwu֮һ���ʹ�á�
      �����޴�busyʱ���Գ� 20 tick +����ս��������
      �������������������ȡ�����Խ����������Խ�ࡣskill*2
������$1�������칦֮�����ھ���̫��Ѩ�߸߹�������𲭣�����ȭ�о������������죬�Ӳ���˼�鷽λ��$1����һ�С�
***************************************************************************************/               
#include <ansi.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void chkpfm(object me, object target, int amount);

int perform(object me, object target)
{
	int skill, damage, time;
	string weapon;
	string *limb, type, result, str;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������޼���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������޼�������ֲ���ʩչ��\n");

	if( me->query_skill_mapped("cuff") != "chunyang-quan" )
		return notify_fail("�����õĲ��Ǵ���ȭ������ʩչ�������޼�����\n");

	if( me->query_skill_prepared("cuff") != "chunyang-quan" )
		return notify_fail("�������Ĳ��Ǵ���ȭ������ʩչ�������޼�����\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("�����õĲ����������칦��ʩչ�����������޼�����\n");

	if( me->query_skill("xiantian-gong",1) < 199 )
		return notify_fail("����������칦���δ�����޷�ʩչ�������޼�����\n");

	if( me->query_skill("chunyang-quan", 1) < 199 )
		return notify_fail("�������޼�����Ҫ��տ�Ĵ���ȭ������Чʩչ��\n");

	skill = me->query_skill("force") / 2 + me->query_skill("chunyang-quan",1);

	if( me->query("neili") <= skill * 3 / 2 )
		return notify_fail("�����������ʹ�á������޼�����\n");
	if( me->query("jingli") <= skill )
		return notify_fail("��ľ�������ʹ�á������޼�����\n");

	message_vision(HIG "\n\n$N�������칦֮�����ھ���̫��Ѩ�߸߹�������𲭣�����ȭ�о������������죬�Ӳ���˼��ķ�λ��$n����һ�У�����\n" NOR, me, target);
	chkpfm(me, target, skill);
	me->add("neili", -(skill * 3 / 2)  );
	me->add("jingli", -skill );
	me->start_busy( 1+random(2) );
	return 1;
}

void chkpfm(object me, object target, int amount)
{
	object weapon2 = target->query_temp("weapon");
        string *limbs, action, limb, attack_skill, dodge_skill, parry_skill, result, msg = "", *type = ({"����","����","����"});
        int ap, dp, pp, damage, level, sp, sp2, ap2;
	if( !me->is_fighting(target) || !living(target) ) 
                return;
	attack_skill = me->query_skill_mapped("cuff");
	action = me->query("actions")["action"];

	damage = amount * ( 2 + random(4));
	ap = COMBAT_D->skill_power(me, SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;
	ap2 = COMBAT_D->skill_power(me, "cuff", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	sp = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
	if( target->is_busy() ) dp /= 4;
	if( dp < 1 ) dp = 1;
	if( random(ap + dp) < dp )
	{
		if (wizardp(me)) tell_object(me,"ap:"+ap+"   dp:"+dp+".\n");
		dodge_skill = target->query_skill_mapped("dodge");
		if ( !dodge_skill ) dodge_skill = "dodge";
		if ( random(dp) < random(sp * 7 / 10) ){
			msg += HIY "\n$n��"+to_chinese(dodge_skill)+"����������һ����������δͣ�ȣ���$N��������ǰ��\n" NOR;
			msg += HIG "\n" + action + "��\n" +NOR;
			target->receive_damage("qi", damage/3, me);
			target->receive_wound("qi", damage/5, me);
			result = COMBAT_D->damage_msg(damage, type[random(sizeof(type))]);
                        msg += replace_string( HIR+result+NOR, "$l", limb );
                }else msg += SKILL_D(dodge_skill)->query_dodge_msg();
	}
	else
	{
		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( target->is_busy() ) pp /= 3;
		if( pp < 1 ) pp = 1;

		if( random(ap + pp) < pp )
		{
			if (wizardp(me)) tell_object(me,"ap:"+ap+"   pp:"+pp+".\n");
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
				parry_skill = "parry";
			if ( random(ap2) > random(pp * 2) && !weapon2 ){
				msg += HIY "\n$n��"+to_chinese(parry_skill)+"����ʽ������һ�������$N����ʽɱ�˾޴�\n" NOR;
				target->receive_damage("qi", damage/10, me);
				target->receive_wound("qi", damage/15, me);
				result = COMBAT_D->damage_msg(damage, type[random(sizeof(type))]);
	                        msg += replace_string( HIR+result+NOR, "$l", limb );
	                }else msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
		}
		else 
		{
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);
			result = COMBAT_D->damage_msg(damage, type[random(sizeof(type))]);
                        msg += replace_string( HIR+result+NOR, "$l", limb );
		}
	}
	message_vision(replace_string( msg, "$l", limb )+"\n", me, target);
	return;
}