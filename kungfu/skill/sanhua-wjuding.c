// Code of ShenZhou
//sanhua-juding.c �����۶���
// sdong 07/98

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ����̧��������ȭб�������Ƽ��������һ�죬����$n����",
	"force" : 145,
        "dodge" : 5,
	"parry" : 15,
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "��̧��"
]),
([	"action" : "$N������̧������ת������б��������ʹ����Գ�׹�������$n���ʺ�",
	"force" : 160,
        "dodge" : 5,
	"parry" : 15,
	"weapon": "����",
        "damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "Գ�׹�"
]),
([	"action" : "$Nʹһʽ������š���ת��̧�⣬�����ڴ����д�����֮������$n��$l",
	"force" : 180,
        "dodge" : 8,
	"parry" : 10,
        "damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "�����"
]),
([	"action" : "$N�������ģ�$n����һ�㣬$N�����صش������һ�����ǡ������֡�",
	"force" : 210,
        "dodge" : -5,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "������"
]),
([	"action" : "$Nʹ������ĥ������������ٿ�ش�����ʳ�ж�ָ�ſ�������������ת������ײ��$n�Է�����",
	"force" : 250,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "����",
	"lvl" : 40,
	"skill_name" : "��ĥ����"
]),
([	"action" : "$N�����͵���$n�ؿ�ײȥ����$n��ʹ���ѽ���Ծ�𣬷���һ�ƣ�ʹ������һ�С���Ƿ���š�",
	"force" : 330,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 50,
	"skill_name" : "��Ƿ����"
]),
([	"action" : "$N������ǰ������һ�С���ϼ���ա������ֻ�ȭΪ�ƣ�����ʮ�㣬����������$n���ؿ�",
	"force" : 410,
	"dodge" : 10,
	"parry" : 15,
	"damage" : 60,
	"damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "��ϼ����"
]),
([	"action" : "$N������Σ�������$n���б����ȥ����һ�С��ϵ紩�ơ�ȴ�Ǽ�������ϳ����������Ƶ�����;��ȥ��ͻ��������������գ���ԵȴҪն�ڵ����Ҿ�",
	"force" : 500,
	"dodge" : 10,
	"parry" : 15,
	"damage" : 80,
	"damage_type" : "����",
	"lvl" : 70,
	"skill_name" : "�ϵ紩��"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="chunyang-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������۶��Ʊ�����֡�\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("����������칦��򲻹����޷�ѧ�����۶��ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������۶��ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("sanhua-juding", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������۶��ơ�\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"sanhua-juding/" + action;
}
