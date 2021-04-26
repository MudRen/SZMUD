// Code of ShenZhou
// ding-unarmed.c һ��һ��ȭ
inherit SKILL;

mapping *action = ({
([	"action" : "$N��������һĨ����$n��$l��ȥ",
	"damage" : 80,
        "damage_type" : "����"
]),
([	"action" : "$N����һ�ᣬ����$n��$l",
	"damage" : 100,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="unarmed" || usage=="parry"; }

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
		return notify_fail("�������������һ��һ��ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

