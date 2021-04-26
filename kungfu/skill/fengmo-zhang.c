// Code of ShenZhou
// fengmo-zhang.c ؤ���ħ�ȷ�
// qfy November 30, 1997

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N��ִ$w�󿪴��أ����һ��裬ʹ������ɲ��·��������$n��$l",
        "force" : 150,
        "dodge" : 2,
        "parry" : 2,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "��ɲ��·",
        "damage_type":  "����"
]),
([      "action":"$Nʩ�����ֻ��޳�������$w��β����ͷ��Ϊ���ļ��ٵ�ת����$w���ź�������ײ��n",
        "force" : 200,
        "dodge" : 0,
        "parry" : 5,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "�ֻ��޳�",
        "damage_type":  "����"
]),
([      "action":"$Nһ�š�������ʯ����˫�ֽ���$w�߾ٹ�����һ����ȣ�$w�����޳����$nͷ������",
        "force" : 250,
        "dodge" : 5,
        "parry" : 5,
        "damage": 40,
        "lvl" : 25,
        "skill_name" : "������ʯ",
        "damage_type":  "����"
]),
([      "action":"$N��$w����ͷ����ת��磬ʹ�����޺��׷𡹰Ѽ�ת�ŵ�$w��$n����������˫�ֺ�ʮ������Ʈǰ�ӹ�$w",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "damage": 50,
        "lvl" : 35,
        "skill_name" : "�޺��׷�",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��һ�ƻ��أ���������һ�С�ħӰ���ء���$w�����Ұ�ȷ磬ָ��$n��$l",
        "force" : 350,
        "dodge" : 10,
        "parry" : 5,
	"damage": 65,
        "lvl" : 45,
        "skill_name" : "ħӰ����",
        "damage_type":  "����"
]),
([      "action":"$NѸ�ٵ�ת��$w������ǰ���һ���һƬ��������Ȼ�س��$nʩչ����ɲ��������$w��$n$l���װ������",
        "force" : 400,
        "dodge" : 10,
        "parry" : 10,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "��ɲ����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("��Ļ����������̫ǳ��\n");
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

	level = (int)me->query_skill("fengmo-zhang",1);
	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ�����������ħ�ȷ���\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fengmo-zhang/" + action;
}
