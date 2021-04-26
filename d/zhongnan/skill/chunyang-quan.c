// Code of ShenZhou
//chunyang.c ����ȭ
//sdong 07/98 

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʩչ�����ײ�ʳ���������ڿ�Ծ�������ſ������ɺ��ٿգ���������ȭ����ͻȻ������ǰ��̽������$n$l",
        "force" : 150,
        "dodge" : 5,
		"parry" : 10,
        "lvl" : 0,
        "skill_name" : "���ײ�ʳ",
        "damage_type" : "����"
]),
([	"action" : "$N����ʹ��������Ϸ�꡹��������μ��У���ȭ��ಡ���һ�����Ʒ����ʹ�����������$n��$l",
	"force" : 200,
        "dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"skill_name" : "����Ϸ��",
	"damage_type" : "����"
]),
([	"action" : "$N���������Ȼŭ��һ������ǰһ��������˫�ơ�Ұ���ϲۡ������ŷ���֮����������$n",
	"force" : 240,
    "dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
	"skill_name" : "Ұ���ϲ�",
    "damage_type" : "����"
]),
([	"action" : "$N�ڿշ���һʽ���ڻ����ġ�����ȭ����$n�ؿ��������͵���ȥ",
	"force" : 280,
    "dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
	"skill_name" : "�ڻ�����",
    "damage_type" : "����"
]),
([	"action" : "$N��ǰһ���ͳ壬һʽ������Ϸ�项��˫ȭͻȻͬʱ������ֱȡ$n��˫Ŀ",
	"force" : 320,
    "dodge" : 10,
	"parry" : 15,
	"lvl" : 38,
	"skill_name" : "����Ϸ��",
    "damage_type" : "����"
]),
([	"action" : "$N�������һ�������ñܿ�$n�Ĺ�����ͻȻһת������һ�С����뷴�ҡ���һ��Ťס$n�۰���ȭȴ����$n������",
	"force" : 360,
    "dodge" : 15,
	"parry" : 10,
	"lvl" : 45,
	"skill_name" : "���뷴��",
    "damage_type" : "����"
]),
([	"action" : "$N��ǰһ����������ʹ����������ʳ����һ�ǹ�ȭ������һ�еص���$n",
	"force" : 400,
    "dodge" : 15,
	"parry" : 10,
	"lvl" : 55,
	"skill_name" : "������ʳ",
    "damage_type" : "����"
]),
([	"action" : "$N������֮�����ͺ�һ����ͻȻһʽ���������ơ�����ȭ��ĳ�죬Ю���ſ�磬�����Ƶ絷��$n$l",
	"force" : 550,
    "dodge" : 15,
	"parry" : 15,
	"lvl" : 65,
	"skill_name" : "��������",
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhua-juding"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("xiatian-gong", 1) < 20)
		return notify_fail("����������칦��򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
	level   = (int) me->query_skill("chunyang-quan",1);
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
	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chunyang-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if(me->query_temp("lianhuan",1))
	{
		victim->receive_damage("qi",damage_bonus*factor);
		victim->receive_damage("max_qi",damage_bonus);
	}
	else ::hit_ob(me, victim, damage_bonus, factor); 
//		  if( random(me->query_skill("qishang-quan", 1)) > 80 ) {
//					 victim->apply_condition("qs_damage",
//					 random(me->query_skill("qishang-quan", 1)/3) + victim->query_condition("qs_damage"));
//		  }

}

