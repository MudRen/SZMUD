// Code of ShenZhou
// jinshe-jianfa.c ���߽��� 
// qfy Nov 22, 1996

inherit SKILL;

mapping *action = ({
([      "action":"$N�������磬һ�С������Ӱ��������$wͻȻ����$n��$l���漴�����ջ�",
	"force" : 125,
	"dodge" : -0,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "�����Ӱ",
	"damage_type":  "����"
]),
([      "action":"$Nʹ������Ӱ�������$w���������һ��Ƭ������һ��������$n��$l",
	"force" : 160,
	"dodge" : -0,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "��Ӱ���",
	"damage_type":  "����"
]),
([      "action":"$N�߶���������ɣ�ʹ����ѩ�ط��ߡ����Ų�������ʵ����$n��ǰ�������������$w������$l",
	"force" : 200,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "ѩ�ط���",
	"damage_type":  "����"
]),
([      "action":"$NѸ�ٹ��ص�������һ�С��������š���$w�ó���㽣�⣬��˸�����ص���$n",
	"force" : 250,
	"dodge" : 10,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type":  "����"
]),
([      "action":"$N�е�$w����һƬ������ʹ�������߿��衹���ڿ��л���һ���������ߣ�ɨ��$n��$l",
	"force" : 300,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "���߿���",
	"damage_type":  "����"
]),
([      "action":"$N���쳤Х��ʩչ�����ߵ���������������$w��ɹ��Σ�ͻȻһ���֣����һ�����մ���$n",
	"force" : 340,
	"dodge" : 5,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "���ߵ���",
	"damage_type":  "����"
]),
([      "action":"$NͻȻ����$nѸ�����ߣ�һ�С�������ǡ���$w�ӳ����������벻����λ���ϣ�$n���ۻ����Ҳ�֪���룬һͷײ����ȥ",
	"force" : 380,
	"dodge" : 10,
	"damage": 75,
	"lvl" : 60,
	"skill_name" : "�������",
	"damage_type":  "����"
]),
([      "action":"$Nɲס���л����鲽���߸߾�������$w������������$wһ�������������������һʽ�����߻���������ʱ���һ���ƿն�������$n��ͷ����",
	"force" : 410,
	"dodge" : 5,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "���߻���",
	"damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("����ڹ��ķ����̫ǳ���޷�ѧϰ���߽�����\n");

	if ((int)me->query_int() < 30)
		return notify_fail("������Բ������޷�������߽�����\n");

	if ((int)me->query_con() < 20)
		return notify_fail("��ĸ��ǲ������޷������߽�����\n");

	if (!present("jinshe miji", me)) 
		return notify_fail("��ϰ���߽�������һ���ж��������ܼ�����\n");

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
	int i, level1, level2, level3;
	object target, anqi;

	level1 = (int) me->query_skill("jinshe-jianfa",1);
	level2 = (int) me->query_skill("youshen-zhang",1);
	level3 = (int) me->query_skill("jinshe-zhuifa",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	if ( level1 >= 120 && level2 >= 120 && random(level2) > level2 * 1/2
	&& me->query_skill_mapped("strike") == "youshen-zhang" 
	&& me->query_skill_prepared("strike") == "youshen-zhang" 
	&& me->query("neili") > 10 && me->query("jingli") > 5 ) {
		weapon->unequip();
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		weapon->wield();
		me->add("neili", -10);
		me->add("jingli", -5);
	}

	if ( level1 >= 120 && level3 >= 100 && random(level3) > level3 * 1/2
	&& me->query("neili") > 10 && me->query("jingli") > 5) {
		if ( objectp(anqi=present("jinshe zhui", me)) ) {
			anqi->throw_ob(me, target);
			me->add("neili", -10);
			me->add("jingli", -5);
		}
	}

	for(i = sizeof(action); i > 0; i--)
		if(level1 > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level1/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������������߽�����\n");

	me->receive_damage("jingli", 25, "����͸֧��������");

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinshe-jianfa/" + action;
}
