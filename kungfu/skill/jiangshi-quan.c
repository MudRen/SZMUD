// Code of ShenZhou
// jiangshi-quan.c ����ȭ
// qfy September 28, 1996.

inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ֱͦ����ǰһԾ������$n��$l",
        "force" : 300,
        "dodge" : 5,
	"parry" : 10,
        "lvl" : 0,
        "damage_type" : "����"
]),
([	"action" : "$N������׵���צ��ץ��$n��$l",
	"force" : 350,
        "dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"damage_type" : "����"
]),
([	"action" : "$Nһ����У�ͦ��˫�ۣ�����$n�ľ���",
	"force" : 400,
        "dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$N��ֱ�������쳤��צ��������������������$n",
	"force" : 450,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N֨֨�ļ��������ͻȻ����$n����צ��$l��Ȼ����",
	"force" : 500,
        "dodge" : 10,
	"parry" : 15,
	"lvl" : 38,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("��ѧ����ȭ���ٺ٣����������ı�����������\n");
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("jiangshi-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"jiangshi-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("jiangshi-quan", 1)) > 30 ) {
                victim->apply_condition("xx_poison", 
                random(me->query_skill("xingxiu-duzhang", 1)/2) + victim->query_condition("xx_poison"));
        }
}
