// Code of ShenZhou
// huzhua-gong.c ��צ��
// snowbird august 99
// 1.1.1.1

inherit SKILL;
mapping *action = ({
([      "action" : "$N˫צһ�ţ�б���������̤�й���һʽ���ڻ����ġ�������Ѹ�磬�񲻿ɵ�����$n�ؿ����Ĺ�ȥ",
        "force" : 100,
        "dodge" : 5,
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "�ڻ�����",
        "damage_type" : "ץ��"
]),
([	    "action" : "$N��������˫�ۻ��ţ�����һչ��һ�С��ͻ���ɽ����˫צ���ɣ����϶��£�����$n����",
	    "force" : 150,
        "dodge" : 10,
	    "damage": 20,
	    "lvl" : 10,
	    "skill_name" : "�ͻ���ɽ",
	    "damage_type" : "ץ��"
]),
([	    "action" : "$N�ù����ƣ�����һʽ��������ʳ�����������ϣ��缲��㣬�۵�$n��ǰ������$n���������Ѩ",
	    "force" : 200,
        "dodge" : 10,
	    "damage": 30,
        "lvl" : 20,
	    "skill_name" : "������ʳ",
        "damage_type" : "����"
]),
([      "action" : "$N����������������Х������һʽ����Х��ɽ������$nһ�֮�䣬�������ǰ���Ͱ�$n˫��",
        "force" : 250,
        "dodge" : 15,
        "damage": 40,
        "lvl" : 30,
        "skill_name" : "��Х��ɽ",
        "damage_type" : "ץ��"
]),
([	    "action" : "$N΢΢һ����һ�С�����β������Ȧ��$n��󣬼���Ʈ�磬ֱ��$n���ץȥ",
	    "force" : 300,
        "dodge" : 15,
	    "damage": 50,
	    "lvl" : 50,
	    "skill_name" : "����β",
        "damage_type" : "ץ��"
]),
([      "action" : "$N��Ӱ���Σ�����ֱ�ϣ�����һʽ���޻����֡����������ߣ�������ת����$n����Ϯȥ",
        "force" : 350,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 80,
        "skill_name" : "�޻�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ�ţ�һԾ���𣬰����ʹ��һʽ�����ڻ�Ծ����Я������֮�ƣ����׼л�֮������$nץȥ",
        "force" : 400,
        "dodge" : 25,
        "damage": 70,
        "lvl" : 100,
        "skill_name" : "���ڻ�Ծ",
        "damage_type" : "ץ��"
]),
([	    "action" : "$N����һ����һʽ�������������ù��Է����ƣ���צ��Ȼ̽����ץ��$n����",
	    "force" : 450,
        "dodge" : 25,
	    "damage": 80,
	    "lvl" : 150,
	    "skill_name" : "��������",
        "damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return  usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ��������֡�\n");
	if ((int)me->query_skill("hongming-xuangong", 1) < 10)
		return notify_fail("����ڹ���Ϊ��򲻹����޷�ѧ��צ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����צ����\n");
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
	    level = (int) me->query_skill("huzhua-gong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������צ����\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huzhua-gong/" + action;
}
