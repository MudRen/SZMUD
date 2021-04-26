// Code of ShenZhou
// xiaoao-jianfa.c ��ң����
//��Լ�������������ڣ��������������Ų������ɽˮ��־��ϼ�̣������뻳����ң���졣

#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *name1 = ({ "����Ѩ", "���Ѩ", "����Ѩ", "����Ѩ", "����Ѩ", "�Ϲ�Ѩ",                   
		   "���Ѩ", "̫��Ѩ", "����Ѩ", "��ǿѨ", "��̨Ѩ" });

mapping *action = ({
([      "action" : "$N$w����������һʽ����Լ��������$w�����·��ض���������ǣ�ʱ��ʱ�ֵ�Ʈ��$n",
	"force" : 170,
	"dodge" : 15,
	"parry" : 15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "��Լ����",
	"damage_type" : "����"
]),
([      "action" : "$N������ˮ�����Ƹ��ƣ�����΢��ݳ�һ�С��������ڡ���$w�滮��$n��$l",
	"force" : 210,
	"dodge" : 25,
	"parry" : 15,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����$wһ������������һ�С�������������������ָ�����⼴���������任�ղ���$n��$l",
	"force" : 270,
	"dodge" : 25,
	"parry" : 20,
	"damage": 55,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "һ�Ľ���֮Ʈ�ݣ�$N��������ȫ����$w��ô󿪴�ͣ���̤�й���һʽ�����Ų����$w���ŷ�����$n��$l��ȥ��",
	"force" : 340,
	"dodge" : 20,
	"parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "���Ų��",
	"damage_type" : "����"
]),
([      "action" : "$N$w��ӣ�һ�С�����ɽˮ��������㽣�ˣ���������һ��ӿ��$n",
	"force" : 380,
	"dodge" : 20,
	"parry" : 20,
	"damage": 70,
	"lvl" : 55,
	"skill_name" : "����ɽˮ",
	"damage_type" : "����"
]),
([      "action" : "$Nһ�С�־��ϼ�̡�������Ʈ��������$w�ֳ�һƬϼ�⣬��ס$N������һ������$n",
	"force" : 400,
	"dodge" : 30,
	"parry" : 20,
	"damage": 80,
	"lvl" : 65,
	"skill_name" : "־��ϼ��",
	"damage_type" : "����"
]),
([      "action" : "$N���ֽ�����$nһ����$w��һ�С������뻳�������⻮��һ��һС����ԲȦ��£��$n��������",
	"force" : 430,
	"dodge" : 20,
	"parry" : 30,
	"damage": 85,
	"lvl" : 75,
	"skill_name" : "�����뻳",
	"damage_type" : "����"
]),
([      "action" : "$N���и��ݣ�һ�С���ң���졹���ϵݳ���$w��Ϊ��ʮ����â���л��㱣�Ʈ����$n",
	"force" : 450,
	"dodge" : 30,
	"parry" : 30,
	"damage": 95,
	"lvl" : 85,
	"skill_name" : "��ң����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenghuo-xuanming",1) < 20)
		return notify_fail("���ʥ����ڤ�����δ�������޷���ϰ��ң������\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
/*
mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("xiaoyao-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/
mapping query_action(object me, object weapon)
{
	int i, level, jq;
	object target;
	string msg, name;       

	level   = (int) me->query_skill("xiaoyao-jianfa",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");
	jq = level / 80;

	name = name1[random(sizeof(name1))];    

	if (me->query_temp("jianqi_1")) {
	return ([
	"action":HIC"$N���ֽ���һת������$w��ס������һƬ������˸������������һ�ɽ�������$n��"+name+"��" NOR,
	"force" : 440+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 100+jq*3,
	"weapon": HIW"����"NOR,
	"damage_type":  "����"
	]);
	}
	if (me->query_temp("jianqi_2")) {
	return ([
	"action":HIG"$N̤ǰһ����$w�ϵڶ��ɽ������յ���$n��"+name+"����Ѩ�������֮�" NOR,
	"force" : 460+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 120+jq*3,
	"weapon": HIW"����"NOR,
	"damage_type":  "����"
	]);
	}
	if (me->query_temp("jianqi_3")) {
	return ([
	"action":HIW"$N��������������$w���������ɽ�����һ����â���ʯ���ֱ��$n������ɨ��$n��"+name+"��" NOR,
	"force" : 490+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 140+jq*3,
	"weapon": HIW"����"NOR,
	"damage_type":  "����"
	]);
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�������������ң������\n");
	me->receive_damage("jingli", 30, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiaoyao-jianfa/" + action;
}
