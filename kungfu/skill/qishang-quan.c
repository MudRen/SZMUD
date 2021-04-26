// Code of ShenZhou
//qishang-quan.c ����ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$N���˼�������������һ�����۹Ǹ�����죬����һ����һȭ����$n$l",
	"force" : 380,
        "parry" : 5,
	"damage": 50,
	"lvl" : 0,
        "damage_type" : "����"
]),
([	"action" : "$N����һ�ڳ����������ֽ��˫��һ������������������֮�������ϣ���һ������$n��$l",
	"force" : 400,
        "parry" : 5,
	"damage": 80,
	"lvl" : 10,
        "damage_type" : "����"
]),
([	"action" :"$N�����ͣ�һȭ��������$n�����عؽ�һŤ���ֱ۱�����ߣ�ȭ����ľ��ҹ�䣬��Х���л���$n��$l",
	"force" : 430,
        "parry" : 15,
	"damage": 80,
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" :"$N���һ����˫ȭ�������������δ��ȭ�ϰ�������ŭ�����࣬��Х���Ϯ��$n",
	"force" : 470,
        "parry" : 5,
	"damage": 80,
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N��Ŀ��ȣ���������������һȭ�����ȭ��������棬��������������ž������֮����ѹ��$n��$l",
	"force" : 420,
        "parry" : 10,
	"damage": 85,
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N˫��һ��һ�ȭ����п�ɽ������һ���������ڣ�ֱ����$n��$n�ؿ�һ����ֻ��������Ż",
	"force" : 480,
        "parry" : 25,
	"damage": 80,
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N˫Ŀ΢�أ�����Ʈ������ƮƮ������ȭ��ȴ�ǰ����ϢҲ�ޣ�$n��ز��΢����壬ȭ��������Ϯ��$l",
	"force" : 550,
        "parry" : 15,
	"damage": 135,
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$Nһ����Х��˫Ŀ��죬ȭ·�󿪴��أ�ÿһȭ������������ŭ��ʯ���쾪���Ժ������ڼ������Ĵ�����",
	"force" : 600,
        "parry" : 20,
	"damage": 100,
	"lvl" : 70,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	if( me->query_skill("force") < 250 
	|| me->query_skill("qishang-quan", 1) < 180 ) {
		me->apply_condition("qs_self_damage", me->query_condition("qs_self_damage") + random(5));
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("qishang-quan", 1)) > 80 ) {
                victim->apply_condition("qs_damage",
                random(me->query_skill("qishang-quan", 1)/3) + victim->query_condition("qs_damage"));
        }

	if ( victim->query_temp("jinzhongzhao") ) {
		victim->apply_condition("qs_damage", victim->query_condition("qs_damage")/3);
	}
}

/*
string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
*/
