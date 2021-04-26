// Code of ShenZhou
// wuhu-gun.c �廢��

inherit SKILL;

mapping *action = ({
([      "action" : "$N��͸����һ�С��ϻ��½١���$w���·��������һ�Ź�Ȧ����$n��$l",
        "force" : 180,
      "parry" : 10,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "�ϻ��½�",
        "damage_type" : "����"
]),
([      "action" : "$N����˫�ۣ�ʹһ�С���ü��������$w�Ƽо��磬��$n��$l��ȥ",
        "force" : 260,
      "parry" : 20,
        "damage" : 20,
        "lvl" : 3,
        "skill_name" : "��ü����",
        "damage_type" : "����"
]),
([      "action" : "$N��һ������һ�С����쳹�ء�������$w����һ���󻡣���$n��$l�ݺ�����",
        "force" : 300,
      "parry" : 10,
        "damage" : 25,
        "lvl" : 8,
        "skill_name" : "���쳹��",
        "damage_type" : "����"
]),
([      "action" : "$N�趯����$w��һ�С�������β�������š����ء���������$n��$l��ɨ����",
        "force" : 330,
      "parry" : 15,
        "damage" : 35,
        "lvl" : 16,
        "skill_name" : "������β",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��ת������������һ�С���ţ���ء�������$w���䲻����ŵؾ���$n��$l",
        "force" : 360,
      "parry" : 25,
        "damage" : 35,
        "lvl" : 24,
        "skill_name" : "��ţ����",
        "damage_type" : "����"
]),
([      "action" : "$N�����ۣ�ʹһ�С��������¡����������٣�$w�������ϳ��𣬹���$n��$l",
        "force" : 420,
      "parry" : 20,
        "damage" : 40,
        "lvl" : 33,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "stick" || usage == "parry" || usage == "club"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
/*
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
                return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
*/
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
        level   = (int) me->query_skill("wuhu-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "stick"
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ����������廢����\n");
        me->receive_damage("jingli", 25);
        return 1;
}
