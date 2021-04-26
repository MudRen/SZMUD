// Code of ShenZhou
// feiyu-bian.c �������澭���޷�
// xQin 8/99 ����������ƮƼ��

#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;

int special(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action" : "�����ֻ����Ӱ������$N�����ǰ��һ��$w��$nӭ��������������׵���������",
	"damage_type" : "����"
]),
([	"action" : "$N�����죬�޷���ã�������$w�������߲��������Ӱ�·�佫������ֱ��$n$l",
	"damage_type" : "����"
]),
([	"action" : "$N���е�$w����һ����˿������û������������Ӻ����������������ˣ���$n����Ʈ������",
	"damage_type" : "����"
]),
([	"action" : "ͻȻ֮�䣬$N����һ��һ�Σ��������ɣ�$w���Ҽ缱˦��󣬶��ػ���$n$l����������������ʸ�ö���",
	"damage_type" : "����"
]),
([	"action" : "$N���ش�$n����һ����������δ����Ȼ�������������۾�һ�㣬$w˵���㵽��ֱָ$n��$l",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N��Ӱ���ߺ��ͣ�Ʈ���鶯������޷���$w�ؽ����������籩�����$n����",
	"damage_type" : "����"
]),
([	"action" : "$N���ڰ�գ���һֻ��װ�����˻����£��������ޱȣ�$w��������׼$n�����������ȥ������Ѹ��֮��",
	"damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
         if (!me->query("emei/feiyu"))
		return notify_fail("������������������ָ��������ܡ�\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, force, dodge, neili;
	object target = offensive_target(me);

	i = random(sizeof(action));
	force = me->query_skill("force");
	dodge = me->query_skill("dodge");
	neili = me->query("neili");

        if( me->query_temp("jiuyin_chanrao/"+target->name()) )
	{
		me->add("neili", -15);
		me->add("jingli", -5);
                me->add_temp("jiuyin_chanrao/"+target->name(), -1);

                if( me->query_temp("jiuyin_chanrao/"+target->name()) < 1 )
		{
                        me->delete_temp("jiyin_chanrao");
			target->start_busy(1);
		}
                else
                {
                     target->start_busy(2);
                }
	}

	if( objectp(me->query_temp("secondary_weapon")) )
	{
		force /= 2;
		neili /= 2;
	}

	return ([
		"action": action[i]["action"],
		"force" : (random(force)+force)/2,
		"damage": 150+(random(neili)+neili)/100,
		"dodge" : (random(dodge)+dodge)/10,
		"damage_type": action[i]["damage_type"],
		"post_action": (: special :)
		]);
}

int practice_skill(object me)
{
	object weapon;
	int level = me->query_skill("feiyu-bian", 1);
	mapping learned = me->query_learned();

	if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "whip" )
		return notify_fail("��û�г��ֵı�������ϰ����ƮƼ�ޡ�\n");

/*
	if( (level <= 360 && level > 270) || (level > 180 && level/2*2 == level)
	|| (level > 90 && level/5*5 == level) || (level/10*10 == level) )
		if( learned["feiyu-bian"] > (level + 1) * (level + 1) - 200 )
			return notify_fail("�㷴����ϰ������ƮƼ�ޣ�ȴ����������ζ���᲻���侫�����ڡ�\n");
*/

	if( (int)me->query("jingli") < 40 )
		return notify_fail("�����������������ϰ����ƮƼ�ޡ�\n");

	me->add("jingli", -30);
	return 1;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	return HIB"$n����$N������޷�����紵������ˮ�͸�Ƽ��ʵ���˼�������ʱ�������������У�����һ����\n"NOR;
}
*/

int special(object me, object victim, object weapon, int damage)
{
	string skill;
	object weapon2;
	int ap, dp;

	if( objectp(weapon2 = victim->query_temp("weapon")) && damage == RESULT_PARRY )
	{
		ap = (int)me->query("neili") / 10 + (int)me->query("jiali")
			+ (int)me->query_skill("whip")
			+ (int)me->query_skill("force");
		dp = (int)victim->query("neili") / 10 + (int)victim->query("jiali")
			+ (int)victim->query_skill("parry")
			+ (int)victim->query_skill("force");
		ap = (ap + random(ap*2)) / 2;

		if( ap > dp * 2 )
		{
			message_vision( weapon->name() +HIW"��"+ weapon2->name() +
				HIW"�ཻ���������һ�죬$Nֻ�����ڷ��ȣ�"+ weapon2->name() +
				HIW"�ѳֲ��������ַɳ���\n"NOR, victim);
			weapon2->unequip();
			weapon2->move(environment(victim));
			victim->reset_action();
		}
		else if( ap > dp )
			message_vision( weapon->name() +"��"+ weapon2->name() +
				"�ཻ���������һ�죬$Nֻ�����ڷ��ȣ�"+ weapon2->name() +
				"��Щ�����֣�\n", victim);
	}

	if( !me->is_fighting(victim) ) return;

	if( objectp(weapon2 = me->query_temp("secondary_weapon")) )
	{
		skill = me->query_skill_mapped(weapon2->query("skill_type"));
		if( (skill == "emei-jian" || skill == "yanxing-dao")
			&& me->query_dex() >= 70 && me->query("jingli") > 200 )
		{
			me->set_temp("weapon", weapon2);
			me->set_temp("secondary_weapon", weapon);
			me->reset_action();

			me->set_temp("action_flag", 1);
			COMBAT_D->do_attack(me, victim, weapon2, TYPE_QUICK);
			me->set_temp("action_flag", 0);

			me->set_temp("weapon", weapon);
			me->set_temp("secondary_weapon", weapon2);
			me->reset_action();
			me->add("jingli", -10);
		}
	}
	else if( damage == RESULT_DODGE && me->query_skill_mapped("finger") == "tiangang-zhi"
		&& me->query_skill_prepared("finger") == "tiangang-zhi" )
	{
		ap = COMBAT_D->skill_power(me, "whip", SKILL_USAGE_ATTACK);
		ap += COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
		if( ap < 1 ) ap = 1;

		dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
		if( dp < 1 ) dp = 1;

        	if( random(ap) > dp )
		{
			if( me->query_skill_prepared("strike") == "jinding-zhang" )
			{
				me->set_temp("restore_jdz", 1);
				me->prepare_skill("strike");
			}
			me->set_temp("tgz_attack", 1);
			me->set_temp("weapon_name", weapon->name());
			weapon->unequip();
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			weapon->wield();
			me->delete_temp("weapon_name");
			me->delete_temp("tgz_attack");
			if( me->query_temp("restore_jdz") )
			{
				me->prepare_skill("strike", "jinding-zhang");
				me->delete_temp("restore_jdz");
			}
		}
	}
	return 1;
}

string perform_action_file(string action)
{
        if (action == "mie" )
        return __DIR__"emei-jian/" + action;
        else
	return __DIR__"feiyu-bian/" + action;
}
