// Code of ShenZhou
// Luan-blade.c �ҵ�
// Ryu
inherit SKILL;

mapping *action = ({
([	"action" : "$N����$w��һ����һ������׼$n��$l����һ��",
	"damage" : 40,
	"force" : 200,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��һ����һ�ã���$n��$lͱȥ",
        "damage" : 60,
        "force" : 250,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��һ����һ�壬����ָ��$n��$l",
        "damage" : 80,
        "force" : 300,
        "damage_type" : "����"
]),
([	"action" : "$N����$wǰһָ��һɨ����������$n��$l",
	"damage" : 100,
	"force" : 350,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }

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
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������ҵ���\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

