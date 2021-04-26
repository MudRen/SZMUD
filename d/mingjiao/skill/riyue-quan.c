// Code of ShenZhou
// /kungfu/skill/riyue-quan.c ����ȭ
// by wsky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N˫üһ�һ�С����³�����˫ȭ΢΢һ�٣�Ȼ��ɿ�Ĵ���$n��$l",
        "dodge": 30,
        "force": 280,
        "skill_name" : "���³���",
        "damage_type": "����"
]),
([      "action": "$N����һ�Σ�����$n����ǰ��˫ȭһ��һ��������Ļ���$n��$l����һ�С��տ���ӯ��",
        "dodge": 10,
        "force": 200,
        "skill_name" : "�տ���ӯ",
        "damage_type": "����"
]),
([      "action": "$N�ҿ�һ����һ�С����»���������ȭһ����Σ���ȭ�����Ļ���$n��$l",
        "dodge": -20,
        "force": 450,
        "damage": 65,
        "skill_name" : "���»���",
        "damage_type": "����"
]),
([      "action": "$N����$n�Ĺ�������ȭ�͵Ĵ���$n��$l������һ�С��������ס�",
        "dodge": 10,
        "force": 350,
        "damage": 60,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$Nһ���������������΢΢Ʈ��һ�С�ʥ���������˫ȭһǰһ��Ĵ���$n��$l",
        "dodge": 10,
        "force": 350,
        "damage": 80,
        "skill_name" : "ʥ�����",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qishang-quan"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");
        if ((int)me->query_skill("shenghuo-xuanming", 1) < 10)
                return notify_fail("��Ļ����󷨻�򲻹����޷��������ơ�\n");

        if ((int)me->query("max_neili") < 60)
                return notify_fail("�������̫�����޷�������ȭ��");
        return 1;
}


int practice_skill(object me)
{

        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("�����������������ȭ��\n");

        if (me->query_skill("riyue-quan", 1) < 50)
                me->receive_damage("jingli", 20);
        else
                me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon) 
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
                return __DIR__"riyue-quan/" + action;
}