// Code of ShenZhou
// duoming-bi.c	�����йٱ�

inherit SKILL;

mapping *action = ({
([      "action": "$Nʹ�������йٱʣ�����$w�󿪴���ɨ��$n��$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "damage_type": "����",
        "lvl" : 0,
        "skill_name" : "�����йٱ�",
]),
	// add more actions
});

int valid_enable(string usage) { return (usage == "pike") || (usage == "parry")
					|| (usage == "halberd");}

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
        level   = (int) me->query_skill("duoming-bi",1);
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
                return notify_fail("��ľ��������������йٱʡ�\n");
        me->receive_damage("jingli", 25);
        return 1;
}

