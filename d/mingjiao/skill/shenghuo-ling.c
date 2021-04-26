// Code of ShenZhou
// shenghuo-ling.c ʥ����

inherit SKILL;

mapping *action = ({
([      "action": "$Nʹ��ʥ���������$w�󿪴���ɨ��$n��$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "damage_type": "����",
        "lvl" : 0,
        "skill_name" : "ʥ����",
]),
	// add more actions
});

// �书���ͣ��ʺ��κα�����
int valid_enable(string usage) { return (usage == "dodge") || (usage == "parry")
					|| (usage == "blade") || (usage == "sword")
					|| (usage == "staff") || (usage == "stick")
					|| (usage == "hammer") || (usage == "club"); }   // more?

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("�������������\n");
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
        level   = (int) me->query_skill("shenghuo-ling",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("��û��������\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���������ʥ���\n");
        me->receive_damage("jingli", 25);
        return 1;
}

