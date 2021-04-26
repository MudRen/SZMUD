// tianyu-qijian.c �����潣

inherit SKILL;

mapping *action = ({
([	"action":"$Nʹһʽ������һ�ߡ�������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 120,
            "dodge" : 0,
	"damage": 30,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type":	"����"
]),
([	"action":"$N����ǰ��ʹ�������羪�硹������$w����һ����������$n��$l",
	"force" : 140,
            "dodge" : 10,
	"damage": 40,
	"lvl" : 9,
	"skill_name" : "���羪��",
	"damage_type":	"����"
]),
([	"action":"$N����$wһ����һ�С����ھ��졹��ббһ�������ó�������$n��$l",
	"force" : 160,
           "dodge" : 5,
	"damage": 50,
	"lvl" : 18,
	"skill_name" : "���ھ���",
	"damage_type":	"����"
]),
([	"action":"$N���н����ॳ���һ����һʽ��������ġ���һ���������$n��$l",
	"force" : 180,
            "dodge" : 10,
	"damage": 100,
	"lvl" : 27,
	"skill_name" : "�������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��ŭ���񻨡�������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
	"force" : 220,
            "dodge" : 15,
	"damage": 100,
	"lvl" : 36,
	"skill_name" : "ŭ����",
	"damage_type":	"����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ���Ż����ա�����׼$n��$lбб����",
	"force" : 260,
            "dodge" : 5,
	"damage": 120,
	"lvl" : 44,
	"skill_name" : "�Ż�����",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ�������ѩ�������󼱶�������������⣬����$n��$l",
	"force" : 320,
            "dodge" : 5,
	"damage": 125,
	"lvl" : 52,
	"skill_name" : "�����ѩ",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ����ӵ�к����$w��ն�������缲�������$n���ؿ�",
	"force" : 380,
            "dodge" : 5,
	"damage": 140,
	"lvl" : 60,
	"skill_name" : "��ӵ�к",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��������ɡ���$wͻȻ���������һƬ���Χ��$nȫ��",
	"force" : 380,
            "dodge" : 5,
	"damage": 150,
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiaowu-xiang", 1)<25
		&& (int)me->query_skill("bahuang-gong", 1)<25
		&& (int)me->query_skill("beiming-shengong", 1)<25)
		return notify_fail("�����ң���ڹ���򲻹����޷�ѧϰ�����潣��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧϰ�����潣��\n");
	if ((int)me->query_skill("sword", 1) <20)
		return notify_fail("��Ļ���������򲻹����޷�ѧϰ�����潣��\n");
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
	level   = (int) me->query_skill("tianyu-qijian",1);
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
		return notify_fail("��ľ��������������潣��\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
