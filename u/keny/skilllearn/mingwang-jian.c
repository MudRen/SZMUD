// Code of ShenZhou
// mingwang-jian.c ������������

inherit SKILL;

mapping *action = ({
([	"action":"$N�ֽ�������$n����ǰ��ߴ������β������ƣ�$n������ǰ�����Ľ����Ѿ�ָ��$n��$l",
	"force" : 120,
        "dodge" : 10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "����",
	"damage_type":	"����"
]),
([	"action":"$N�����ֳ��������������˸��������ӡ�����ֽ�һȥǧ��ֱ��$n��$l",
	"force" : 140,
        "dodge" : 15,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "���ֳ���",
	"damage_type":	"����"
]),
([	"action":"$Nʹ��һʽ��ɽ��������̤�鲽���������ϣ���ʽ���ͣ�����ɽ�����Ѱ���$n��ͷ����",
	"force" : 160,
        "dodge" : 20,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "ɽ��",
	"damage_type":	"����"
]),
([	"action":"$N��Ӱ�ζ������𡸽�ħ�衹���������������ԣ����Ƶ�$n�������������",
	"force" : 180,
        "dodge" : 30,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "��ħ��",
	"damage_type":	"����"
]),
([	"action":"$N���𡸺��衹����ɫ��Ȼ���Ų���ǰ������ƽ��$n��$l",
	"force" : 200,
        "dodge" : 25,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "����",
	"damage_type":	"����"
]),
([	"action":"$N�������ڡ�����ǰ���ϣ����н��ƽ�欣����绯���㽫$n��ȫ�����ڽ���֮��",
	"force" : 240,
        "dodge" : 30,
	"damage": 45,
	"lvl" : 45,
	"skill_name" : "����",
	"damage_type":	"����"
]),
([	"action":"$Nʹ��һ�С���ڤ����������Ŀת����$n���֮�ʣ���Ȼ���𳤽�����ͷ����",
	"force" : 280,
        "dodge" : 20,
	"damage": 55,
	"lvl" : 54,
	"skill_name" : "��ڤ����",
	"damage_type":	"����"
]),
([	"action":"$N����ǧ��ת����������������㼱ת������$n������ߴ�������ͣס����������ƽն",
	"force" : 320,
        "dodge" : 25,
	"damage": 60,
	"lvl" : 63,
	"skill_name" : "ǧ��ת",
	"damage_type":	"����"
]),
([	"action":"$Nɫ��ͨ��һʽ���������졹�������������ˮ��й�ذ���$nȫ������",
        "force" : 360,
        "dodge" : 30,
        "damage": 65,
        "lvl" : 72,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }


int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
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
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ���������������������\n");
	me->receive_damage("jingli", 25);
	return 1;
}

/*string perform_action_file(string action)
{
	return __DIR__"mingwang-jian/" + action;
}
*/
