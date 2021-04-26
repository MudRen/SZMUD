// Code of ShenZhou
// huifeng-jian.c �ط������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ�����Ϯ�¡�������ƽָ��������磬һ���ǳ��͹�$n��$l",
	"force" : 120,
	"dodge" : 30,
	"damage" : 20,
	"lvl" : 0,
	"skill_name" : "���Ϯ��",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ��Ʈѩ���ơ�ֱ��$n��$l",
	"force" : 140,
	"dodge" : 20,
	"damage" : 30,
	"lvl" : 10,
	"skill_name" : "Ʈѩ����",
	"damage_type" : "����"
]),
([	"action" : "$N$wбָ���죬һʽ��ǧ�徺�㡹���������������⣬����$n��$l",
	"force" : 170,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 20,
	"skill_name" : "ǧ�徺��",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ���������ڡ���$w���϶��»�������һ���󻡣�ͻȻ������$n�̳�",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����š����һʽ��������������$w����ƽ��������$n���ظ�ҪѨ",
	"force" : 250,
	"dodge" : 5,
	"damage" : 60,
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��������ɳ����ȫ������ƽ�ɣ�����һ����������$n��$l",
	"force" : 300,
	"dodge" : 10,
	"damage" : 70,
	"lvl" : 50,
	"skill_name" : "������ɳ",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ�����������Ρ���$w���ַɳ����������㰿������ƿ�����$n��$l",
	"force" : 350,
	"dodge" : 5,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų�������ѩ����â����ҫ���",
	"force" : 400,
	"dodge" : 0,
	"damage" : 90,
	"lvl" : 70,
	"skill_name" : "��غ���",
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="yanxing-dao"; }

int valid_learn(object me)
{
	return notify_fail(HIR"�Բ������Ļط������96-SR���Ѿ����ڣ������������µİ汾����\n"
			   "��ѶϢ�뵽���ҵ������԰崦��ѯ������ͻ����񲿵ľ���ʦ̫��ϵ��\n"NOR);

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
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
	level   = (int) me->query_skill("huifeng-jian",1);
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
		return notify_fail("��ľ����������ط��������\n");
	if ( me->query_skill("huifeng-jian", 1) < 100 )
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}

