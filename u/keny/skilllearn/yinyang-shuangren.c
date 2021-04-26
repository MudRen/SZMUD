//yinyang-shuangren.c  ����˫��
//Jiuer /9/30/2001      �����ׯ�� ���ҹ���

inherit SKILL;

mapping *action = ({
([	"action" : "$N���д�һ�������С���һʽ���Ĺȴ����������е�$w���˸�ԲȦֱ�Ƶ�$n��$l",
	"force" : 100,
	"dodge" : 5,
	"damage" : 15,
	"lvl" : 0,
	"skill_name" : "�Ĺȴ���",
	"damage_type" : "����"
]),
([      "action" : "$N����$w����Խ��Խ��һ�С���Ȧ�ƵС���$w���Ƶ�$n��$l��ֱ������",
        "force" : 120,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 5,
		"skill_name" : "��Ȧ�Ƶ�",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������衹�������е�$w��ǰ��ɻ��δ���$n��$l",
        "force" : 140,
        "dodge" : 10,
        "damage" : 55,
        "lvl" : 15,
		"skill_name" : "�������",
        "damage_type" : "����",
]),
([      "action" : "$Nһʽ���������������$w������������Ŵ���$n��$l",
        "force" : 160,
        "dodge" : 10,
        "damage" : 85,
        "lvl" : 30,
		"skill_name" : "��������",
        "damage_type" : "����",
]),
([      "action" : "$N$w��ǰһ�ᣬһ�С����Ӱݷ𡹣�$w����б��$n",
        "force" : 180,
        "dodge" : 15,
        "damage" : 120,
        "lvl" : 45,
		"skill_name" : "���Ӱݷ�",
        "damage_type" : "����",
]),
([  	"action" : "$N���һ����һ�С��������ҡ�������$w�������ʱ�����䵶����$w�漴�̳�",
    	"force" : 200,
    	"dodge" : 15,
    	"damage" : 100,
    	"lvl" : 60,
		"skill_name" : "��������",
    	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("yinyang-shuangren",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ�������������˫�С�\n");
	me->receive_damage("jingli", 20);
	return 1;
}

