// Code of ShenZhou
// liangyi-dao.c 华山反两仪刀法
// qfy September 7, 1996

inherit SKILL;

mapping *action = ({
([      "action":"$N向$n顺力道砍去，只见$w已从$n面前横扫过去",
        "force" : 150,
        "dodge" : 10,
        "parry" : 10,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "混沌一破",
        "damage_type":  "割伤"
]),
([      "action":"$N身形闪动将$w由正为反向$n挥了过去",
        "force" : 250,
        "dodge" : 15,
        "parry" : 15,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "太乙生萌",
        "damage_type":  "割伤"
]),
([      "action":"$N将内力灌入$w内，招未至，力先到，$n身不由己的飞了出去",
        "force" : 300,
        "dodge" : 10,
        "parry" : 10,
        "damage": 40,
        "lvl" : 25,
        "skill_name" : "两仪合德",
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("zixia-gong", 1) < 25)
                return notify_fail("你的紫霞神功火候太浅。\n");
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
        level   = (int) me->query_skill("liangyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练反两仪刀法。\n");
        me->receive_damage("jingli", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"ah6j/" + action;
}

