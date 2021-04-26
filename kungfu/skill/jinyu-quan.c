// Code of ShenZhou
// jinyu-quan.c ����ȭ

inherit SKILL;

mapping *action = ({
([      "action" :
"$N���λζ���˫ȭһǰһ��һʽ������쵡���Ȼ����$n��$l",
        "force" : 60,
        "dodge" : 0,
        "parry" : 5,
	 "damage": 0,
        "lvl" : 0,
        "skill_name" : "�����",
        "damage_type" : "����"
]), 
([      "action" :
"$N������ȭ�����ֻ��أ�����������һʽ�������Ͻ𡹣�һȭ����$n",
        "force" : 130,
        "dodge" : 5,
        "parry" : 5,
         "damage": 15,
        "lvl" : 10,
        "skill_name" : "�����Ͻ�",
        "damage_type" : "����"
]),
([      "action" :
"$Nһʽ���������񡹣�����һԾ��˫ȭ������͵Ļ���$nͷ��",
        "force" : 195,
        "dodge" : 15,
        "parry" : 5,
         "damage": 20,
        "lvl" : 20,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :
"$N˫ȭƽ�죬˫����һ������һʽ���������⡹���������$n",
        "force" : 250, 
        "dodge" : 15,
        "parry" : 25,
         "damage": 15,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :
"$N����һ�࣬�����Ƶ��ҽţ�ȫ������ѹ����ȭ��һʽ����ʯ��١�����������$n��$l",
        "force" : 290,
        "dodge" : 5,
        "parry" : 30,
         "damage": 25,
        "lvl" : 40,  
        "skill_name" : "��ʯ���",
        "damage_type" : "����"
]),
([      "action" :
"$N˫��һ������������У�һʽ���������á�����Ȼ��ȭ���в�����������$n���ɲ�",
        "force" : 320,
        "dodge" : 25, 
        "parry" : 20,
         "damage": 31, 
        "lvl" : 50,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :
"$Nһʽ����ʯ�ɽ𡹣��Ų�һ��ӿ죬�͵��Ƶ�$n�Ĳ��棬˫ȭ��������$n$l",
        "force" : 380, 
        "dodge" : 30,
        "parry" : 25,
         "damage": 38,
        "lvl" : 60,
        "skill_name" : "��ʯ�ɽ�",
        "damage_type" : "����"
]),

([	"action" : 
"$N��Ȼ˫�۱�����˫ȭ�͵ļӿ죬һʽ���ڿ���𡹶�ʱ����ȭ�⣬����$n������",
	"force" : 430,
        "dodge" : 20,
	"damage": 50,
	"lvl" : 70,
	"skill_name" : "�ڿ����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qingyan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
	level   = (int) me->query_skill("jinyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinyu-quan/" + action;
}
