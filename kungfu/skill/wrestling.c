// Code of ShenZhou
//Ryu

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�����հ⡹���������Ŵ�$nҸ�´�������$n�ľ�����������",
	"dodge" : 0,
	"damage" : 80,
        "damage_type" : "����"
]),
([	"action" : "$N���ִ�$nв�´�����ȥ���������֣����ֳ�$n��$l����",
	"damage" : 70,
	"dodge" : -10,
        "damage_type" : "����"
]),
([      "action" : "$N�������죬ͻȻ����ǰȥ��ͦͷ��$n$lײȥ",
        "damage" : 80,
	"dodge" : -10,
        "damage_type" : "����"
]),
([      "action" : "$N�̴�Ť����˫�ֺϱ�ס$n���������ݣ���Ťס$n��С�ȣ���������ˤȥ",
        "damage" : 90,
	"dodge" : -20,
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ����ɽ�ʡ�����ס$n�ᾱ�������ͺȣ�˫�ֻ��棬�þ�����",
        "damage" : 100,
	"dodge" : -10,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	me->receive_damage("jingli", 30);
	return 1;
}

