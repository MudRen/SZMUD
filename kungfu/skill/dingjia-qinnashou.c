// Code of ShenZhou
// dingjia-qinnashou.c ����������
// xQin 7/00

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ�С���β�֡��������Ƹ���Ȧ������ȥץס��$n������һŤ��",
        "force" : 180,
        "dodge" : 6,
        "lvl" : 0,
        "skill_name" : "��β��",
        "damage_type" : "Ť��"
]),
([      "action" : "$N����ʹ��һ�С������֡����������������ֱ�ȥץ$n�ļ�ͷ��",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 20,
        "skill_name" : "������",
        "damage_type" : "ץ��"
]),
([      "action" : "$NͻȻһ�С�����ץ����˫��һǰһ��ֱȡ$n����硣",
        "force" : 260,
        "dodge" : 15,
        "lvl" : 35,
        "skill_name" : "����ץ",
        "damage_type" : "ץ��"
]),
([      "action" : "$N����һ�С���צ�֡���ץ��$n���ĺ�ġ���̨Ѩ����",
        "force" : 300,
        "dodge" : 19,
        "lvl" : 48,
        "skill_name" : "��צ��",
        "damage_type" : "����"
]),
([      "action" : "$N����ʹ��һ�С���Ů���롹������ֱ͸��ָָ�⣬����$n�ĺ�����",
        "force" : 360,
        "dodge" : 22,
        "lvl" : 56,
        "skill_name" : "��Ů����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����������ֱ�����֡�\n");
        if ((int)me->query_skill("taixuan-gong", 1) < 40)
                return notify_fail("���̫������򲻹����޷�ѧ���������֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������������֡�\n");
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
        level   = (int) me->query_skill("dingjia-qinnashou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������������֡�\n");
        me->receive_damage("jingli", 25);
        me->add("shen", -10);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"dingjia-qinnashou/" + action;
}
