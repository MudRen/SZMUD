// Code of ShenZhou
// San-sword, ɢ��
// Ryu
inherit SKILL;

mapping *action = ({
([	"action" : "$Nһ���󣬽���һ��������$n��$l",
	"damage" : 40,
	"force" : 200,
        "damage_type" : "����"
]),
([      "action" : "$Nһ������һ��$w��ն��$n��$l",
        "damage" : 60,
        "force" : 250,
        "damage_type" : "����"
]),
([      "action" : "$Nһ̧�ۣ�$wһ�ָ��$n��$l",
        "damage" : 80,
        "force" : 300,
        "damage_type" : "����"
]),
([	"action" : "$N$wһ�գ���һ��������$n��$l",
	"damage" : 100,
	"force" : 350,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

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
		return notify_fail("�������������ɢ����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

