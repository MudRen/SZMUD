//    ����ȭ

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ�����ա��־�����ȭ������ȭʽ�������ޣ��ƺ�������������ȴ�־�ֱϮ��$n",
	"force" : 100,
	"dodge" : 5,
	"parry" : 1,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־���ȭ�к����Ϳ�����Ʋ����·�����ȭ��ȴֱָ$n��$l",
	"force" : 120,
	"dodge" : -2,
	"parry" : 2,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־�����ȭ�ƺ��ɶ��д�����������������ʽȴ���ͱ��ˣ��ݺݵػ���$n",
	"force" : 140,
	"dodge" : 3,
	"parry" : -2,
	"lvl" : 6,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����ɡ��־�����ȭ����������������ػ�������ƮƮ�ػ���$n��$l",
	"force" : 160,
	"dodge" : -5,
	"parry" : -1,
	"lvl" : 12,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����硹�־�����ȭ����������һ����磬$n�վ������壬ȭ�о���Ϯ������ǰ",
	"force" : 180,
	"dodge" : -3,
	"parry" : 2,
	"lvl" : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ͨ���־���ȭ���۶���ɢ�����д�֮ͨ�Σ�ֱ��$n��$l",
	"force" : 200,
	"dodge" : 5,
	"parry" : -3,
	"lvl" : 28,
	"skill_name" : "ͨ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����ݡ��־���ȭ�߿�����������ݣ�����ʵ�أ�������$n���ض�ȥ",
	"force" : 220,
	"dodge" : 1,
	"parry" : 1,
	"lvl" : 35,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����Ρ��־���ȭ�����Σ����ڰ��ΰ��ѣ�$nһʱ��ڣ�ȭ����Ȼ����",
	"force" : 250,
	"dodge" : 4,
	"parry" : -1,
	"lvl" : 40,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����塹�־�����ȭֱ����ȭʽ�������ᣬ��$n��$l��ȥ",
	"force" : 280,
	"dodge" : 3,
	"parry" : 2,
	"lvl" : 46,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ������־��������ʵ�֮�Σ�ȭ����Ȼ�Գ���;ĩ·��ȴ����ɱ������$n��������ʩ��ȭ",
	"force" : 310,
	"dodge" : -3,
	"parry" : 0,
	"lvl" : 53,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����С��־�����ȭ������������ƫ���У�����ָ�����У�ȭ��ȴ��$n��������ס",
	"force" : 340,
	"dodge" : -3,
	"parry" : 4,
	"lvl" : 59,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����Ū���־���ȭ�ж�Ȼ���Σ�������Ū$n��ȴ�ְ�������",
	"force" : 370,
	"dodge" : 1,
	"parry" : 3,
	"lvl" : 65,
	"skill_name" : "Ū�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ͯ���־�����ȭ����ͯ������·������һ���$n��$l",
	"force" : 400,
	"dodge" : 3,
	"parry" : 4,
	"lvl" : 72,
	"skill_name" : "ͯ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ����ӹ���־�����ȭ����ʱ����򵥵���ʽ��ƽƽ���棬����ȴ��ס��$n����·",
	"force" : 440,
	"dodge" : 3,
	"parry" : -2,
	"lvl" : 78,
	"skill_name" : "ӹ�־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ���������־������������繭��ȭ���Ƽ���Ѹ�ݵ�Ϯ��$n",
	"force" : 480,
	"dodge" : 5,
	"parry" : 2,
	"lvl" : 85,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([      "action" : "$Nʹ�����桹�־�������������棬ȭ��Ҳ�����䶯��$n���޷��ж���һȭ������",
	"force" : 530,
	"dodge" : 8,
	"parry" : -1,
	"lvl" : 95,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

//int valid_combine(string combo) { return combo=="xuanfeng-tui"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ����ȭ������֡�\n");
	if (me->query("max_neili") >= 1000) return 1;
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("����ڹ���򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 250)
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

	level   = (int) me->query_skill("kongming-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("kongming-quan", 1);
	int i = sizeof(action);
	mapping learned = me->query_learned();

	if (!mapp(learned)) learned = ([]);
	if (!learned["kongming-quan"])
		while (i--) 
			if (lvl == action[i]["lvl"])
				return notify_fail("�㽫�Ѿ�ѧ���������ʽ��ϰ��һ�飬���������ȥ������ͯѧ�µ���ʽ���޷���ý����ˡ�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("jingli") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -25);
	return lvl / 5 + me->query("int") / 3;
}

string perform_action_file(string action)
{
      return __DIR__"kongming-quan/" + action;
}
/*
mixed hit_ob(object me, object victim, int damage)
{
	if (me->query_temp("kongming_berserk")) 
		return damage;
	else return 0;
}

int ob_hit(object ob, object me, int damage)
{
	if (me->query_temp("kongming_berserk")) 
		return damage;
	else return 0;
}
*/