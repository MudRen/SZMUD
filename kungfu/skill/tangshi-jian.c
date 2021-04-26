// Code of ShenZhou
//tangshi-jian.c
//Jay 2/18/97

inherit SKILL;

mapping *action = ({
([	"action" : "$N��ǰ����һ����ͬʱ���д�һ����һʽ�����̺�������ֱ��$n��$l",
	"force" : 10,
	"dodge" : 5,
	"damage" : 10,
        "lvl" : 0,
	"damage_type" : "����"
]),
([      "action" : "$N��ǰ������һ�С�������СС����$w��ǰ���$n��$l",
        "force" : 10,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$N���ַ��ڶ�����棬�·�������ʲô��һ�С������羪�硹�������е�$w��ǰ����$n��$l",
        "force" : 10,
        "dodge" : 5,
        "damage" : 5,
        "lvl" : 5,
        "damage_type" : "����",
]),
([      "action" : "$Nһʽ����ɽ�����ӡ�������$w�Ľ�����һ�Ⲽһ������$n��$l",
        "force" : 20,
        "dodge" : 10,
        "damage" : 10,
        "lvl" : 10,
        "damage_type" : "����",
]),
([      "action" : "$N$w��ǰһ�ᣬһ�С��Ǻ᲻�ҹ�����$w����$n",
        "force" : 20,
        "dodge" : -5,
        "damage" : 25,
        "lvl" : 15,
        "damage_type" : "����",
]),
([  	"action" : "$N���һ����һ�С������д�㡹��������$n������$w�漴�̳�",
    	"force" : 20,
    	"dodge" : 15,
    	"damage" : 20,
    	"lvl" : 20,
    	"damage_type" : "����",
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tangshi-jian",1);
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
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ�����������ʬ������\n");
	me->receive_damage("jingli", 20);
	return 1;
}

string perform_action_file(string action) 
{
       return __DIR__"tangshi-jian/" + action; 
}
