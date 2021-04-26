// SKILL liuyang-zhang.c ��ɽ������
// Modified by xuanyuan 8/2001

#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;
int baihong(object me, object victim, int damage);

mapping *action = ({

([	"action" : "$Nһ�С�������ѩ�����������»�����춻���$n���Ƶ�ͬʱ��������",
	"force" : 150,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 0,
	"skill_name" : "������ѩ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������˫�����������׳ʣ���ͬ������������Ѳ��������й���$n����Ҫ��",
	"force" : 180,
	"dodge" : 30,
	"damage" : 35,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),

([	"action" : "$N������ת��һ�С������������������ݿصþ����ޱȣ����������빥��$n$l",
	"force" : 200,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 70,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��ɽ����������ʹ����һ�С�С�����������ư�����ӿ�߶��������ƿ�$n���أ�������֮����",
	"force" : 230,
	"dodge" : 20,
	"damage" : 10,
	"lvl" : 80,
	"skill_name" : "С����",
	"damage_type" : "����"
]),

([	"action" : "$N����ƽ�ӣ�һ�С����������������Ʈ�ݣ��������������$n$l",
	"force" : 260,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 90,
        "weapon":"����",
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$N������Х��һ�С��������硹������֮����Ȼ��ֹ���Ʒ�����緢�Ѳ�֮����$n������Ϣһ��",
	"force" : 300,
	"dodge" : 30,
	"damage" : 80,
	"lvl" : 120,
	"skill_name" : "��������",
	"damage_type" : "����"
]),

([	"action" : "$N����б��ʹ��һʽ����������������Ƽ�����$n��������Ѩ������ͬʱЮ����������ĳ�",
	"force" : 350,
	"dodge" : 10,
	"parry" : 10,
	"damage" : 100,
	"lvl" : 150,
	"skill_name" : "�������",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="parry"||usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");
	if ((int)me->query_skill("xiaowu-xiang", 1)<50
		&& (int)me->query_skill("bahuang-gong", 1)<50
		&& (int)me->query_skill("beiming-shengong", 1)<50)
		return notify_fail("�����ң���ڹ���򲻹����޷�ѧϰ��ɽ�����ơ�\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷�ѧϰ��ɽ�����ơ�\n");
	if ((int)me->query_skill("strike", 1) <80)
		return notify_fail("��Ļ����Ʒ���򲻹����޷�ѧϰ��ɽ�����ơ�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, busy_time;
	object target = offensive_target(me);
	object victim;
	string *limbs, limb, msg;

	level = (int)me->query_skill("liuyang-zhang", 1);
	victim = me->select_opponent();
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	busy_time = level/20;

	if( random(me->query_temp("lingjiu/baihong")) > 50 || me->query_temp("baihong_attack") ) 
	{
		switch( me->query_temp("baihong_attack") )
		{
			case 1: msg = "����$N����һ���������ƹ�$N�����ӣ�ֱ����$p$l";
				break;
			case 2: msg = WHT"˭֪$Nһ��δ�ߵڶ����������������ؾ����������糤��֮�Σ���������"NOR;
				break;
			default: msg = WHT"ͻȻ��$N�����ƿգ�����$n"+limb+"���������棬�����絶��ת��б��$p$l"NOR;
				break;
		}

		me->add_temp("lingjiu/baihong", -1); 
		me->add("neili", -30);

		if( wizardp(me) )
			tell_object(me, sprintf("\nap: %d", COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK)));

		return ([
			"action": msg,
			"force" : 380+random(120),
			"dodge" : 10,
			"damage": 120+random(80),
			"damage_type":"����",
			"post_action": (: baihong :)
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("����ɽ�����Ʊ�����֡�\n");
	if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ�����������ɽ�����ơ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������ɽ�����ơ�\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
int baihong(object me, object victim, int damage)
{
	int level = (int)me->query_skill("liuyang-zhang", 1)/2;

	me->add_temp("baihong_attack", 1);

	if( damage == RESULT_DODGE && me->query_temp("baihong_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("baihong_attack") == 1 )
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		else me->delete_temp("baihong_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("baihong_attack");
	return 1;
}

