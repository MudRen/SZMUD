// ruyi-dao.c ���⵶

inherit SKILL;

mapping *action = ({
([     "action" : "$N����$wбָ��һ�С�˫��˫�ɡ�����ת$w���Ե�����$n��$l��ȥ",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "˫��˫��",
	"damage_type" : "����"
]),
([      "action" : "һʽ��������������$N���ֳֵ����������������$w��������������$n��$l",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
        "skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����ʹ����������Ϭ������Ȼ������Ȼ�����ֳ�$w��һ������Ϯ������������һ��������ն��$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "������Ϭ",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С��������ԡ���$w��Ӱ���ε��ٷ���һ������ֱ����$n��$l",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$Nһʽ������ʯ�á���һ������˫�ֽ���$w�������б��$n��$l",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
        "skill_name" : "����ʯ��",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��һ�С�����������������������ÿһ���������ͽǶȶ���ͬ��������أ���������$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
        "skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�Я�����ġ�����Ծ��֮�ƣ�����˫���˵���$w�ƿն��£�Ю��������$n��$l�����������ƿյĵ�Х��",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "Я������",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С����δ�������������˫�ֲ�ס����$w��ÿ�����߾ٹ�ͷ��ʱ��ֱ����ʱ��б��",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "���δ�",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiaowuxiang", 1)<25
		&& (int)me->query_skill("bahuang-gong", 1)<25
		&& (int)me->query_skill("beiming-shengong", 1)<25)
		return notify_fail("�����ң���ڹ���򲻹����޷�ѧϰ���⵶��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧϰ���⵶��\n");
	if ((int)me->query_skill("blade", 1) <20)
		return notify_fail("��Ļ���������򲻹����޷�ѧϰ���⵶��\n");
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
	level   = (int) me->query_skill("ruyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������������⵶��\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
	return 1;
}
string perform_action_file(string action)
{
    return __DIR__"ruyi-dao/" + action;
}
