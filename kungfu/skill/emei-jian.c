//Cracked by Kafei
// emei-jian ���ҽ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action": "$N�ɲ���ǰ��$wһ��������$n��ǰ��һ�С���ʽ�ֽ𡹣�ָ��$p��$l����಻����磬���������ͣ",
	"force" : 120,
	"dodge" : 30,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "��ʽ�ֽ�",
	"damage_type": "����"
]),
([	"action": "$N$wб�ߣ�������㣬����ʹһ�С�˳ˮ���ۡ���$w��ǰһ�ͣ��������������$n��$l��ȥ",
	"force" : 140,
	"dodge" : 20,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "˳ˮ����",
	"damage_type": "����"
]),
([	"action" : "$N����һ�Σ��������ɣ�$w������ָ��$n��ǰ��һ�С��𶥷�⡹���𽣳�������$n$l���˹�ȥ",
	"force" : 170,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 20,
	"skill_name" : "�𶥷��",
	"damage_type": "����"
]),
([	"action" : "$N����΢�࣬�Ѵ�$n�����ƹ�������һ˲֮�䣬��$p��$lն��һ�����ַ���죬����һ�С���б��᡹",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 30,
	"skill_name" : "��б���",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�С�������ɽ�����潣�ߣ�������ε���$n���ᣬ�Ų�δ���������ȵ���$w��������$p$l��ȥ",
	"force" : 250,
	"dodge" : 5,
	"damage" : 60,
	"lvl" : 40,
	"skill_name" : "������ɽ",
	"damage_type" : "����"
]),
([	"action" : "������â���£������Ƿɣ�$Nһ�С������Ὥ�����Ͷ��ϣ���������֮������˪��������������",
	"force" : 300,
	"dodge" : 10,
	"damage" : 70,
	"lvl" : 50,
	"skill_name" : "�����Ὥ",
	"damage_type" : "����"
]),
([	"action" : "�����$Nһ����߳������������趯$w��$n����������һ�С��𶥾�ʽ��������$n����ҪѨ��ȥ",
	"force" : 350,
	"dodge" : 5,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "�𶥾�ʽ",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N����һ����һ�С�ǧ�徺�㡹��$w�Ӷ��������߿��裬���������ϣ�ż����ʵ��ã����к���",
	"force" : 400,
	"dodge" : 0,
	"damage" : 90,
	"lvl" : 70,
	"skill_name" : "ǧ�徺��",
	"damage_type" : random(2)?"����":"����"
]),
([	"action": "����$N���δ�����ȥ�������������ף���һ�̣���һ����չ���������������Խ��Խ�죬��������",
	"force" : 450,
	"dodge" : 10,
	"damage": 100,
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type" : random(2)?"����":"����"
]),
([	"action": "$N����Ǽ⣬ʹ�С�����С�ȡ�����һ���������������죬�����������������ҵ����ξ��£�������Ѱ������ÿһ��ȴ�ֶ��������",
	"force" : 500,
	"dodge" : 0,
	"damage": 110,
	"lvl" : 90,
	"skill_name" : "����С��",
	"damage_type": random(2)?"����":"����"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("linji-zhuang", 1) < 20 )
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for( i = sizeof(action)-1; i >= 0; i-- )
		if( level >= action[i]["lvl"] )
			return action[random(i)]["skill_name"];
}

string *juejian_msg = ({ 
	"�����$N$w���������������������ָ����$n$l��ǡ������糸�����к���֮��",
	"$N$wһ�Σ�����$n$l��ȥ������ز�÷��裬���ֺ��ϣ����������з��������޶�",
	"ȴ��$NƮ����ϣ�����оٽ������������ѷ�ס��$n��������֮�أ����þ����ޱ�",
	"$N��ǰ������������磬�����������棬$w�����������$n�������������Ǽ������Ĺ���",
	"$Nһ�������ݵ�$n��ǰ������΢�����ӽ�б�ã�����$n$l�����������鶯���",
});

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("emei-jian", 1);

	if( me->query_temp("perform/juejian") )
	{
		return (["action": me->query_temp("perform/juejian") == 1 ?
				HIR"$N$w"HIR"΢�࣬��һ�б㼴����������ֱָ$n����ҪѨ������֮�����ͺ���ֱ�Ƿ�����˼"NOR
				: juejian_msg[random(sizeof(juejian_msg))],
			 "force" : 500,
			 "dodge" : 50,
			 "damage": 250,
			 "damage_type": random(2)?"����":"����" ]);
	}
	else for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("jingli") < 50 )
		return notify_fail("��ľ������������ҽ�����\n");

	if( me->query_skill("emei-jian", 1) < 100 )
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"emei-jian/" + action;
}
