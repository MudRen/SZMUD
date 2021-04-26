// Code of ShenZhou
// jinshe-z.c
// ����������
// A.P. 11.12.1996

inherit SKILL;

mapping *action = ({
([      "action": "$N��̤���в���˫�����·��ɣ�ʹ����ǧ�߳���������$n�����ĳ�",
	"dodge": 0,
	"force": 140,
	"lvl"  : 0,
	"damage_type": "����"
]),
([      "action": "$Nʹ�����������ߡ�����Ӱ�ζ���һ�ƴ�����ɽ֮����$n��$l����",
	"dodge": 5,
	"force": 160,
	"lvl"  : 5,
	"damage_type": "����"
]),
([      "action": "$N����һ����ȡ��ߣ�����˫����������ϻ�����˫�����项��ն��$nͷ������",
	"dodge": -5,
	"force": 180,
	"lvl"  : 10,
	"damage_type": "����"
]),
([      "action": "$Nʩ��һ�С�����ʽ����̤�����β�����$nתȦ������$n�ۻ����ң�ͬʱ�������������",
	"dodge": 10,
	"force": 200,
	"lvl"  : 15,
	"damage_type": "����"
]),
([      "action": "$N���ֶԿջ����ţ������������������Ƴ���һ�С�����ʽ��������$n��$l",
	"dodge": 0,
	"force": 220,
	"lvl"  : 20,
	"damage_type": "����"
]),
([      "action": "$NͻȻ����һ���������棬˫�Ʋ�����һʽ���������ơ���������ȵ�������$n��С��",
	"dodge": 5,
	"force": 250,
	"lvl"  : 25,
	"damage_type": "����"
]),
([      "action": "$N����һ���$n����Ҹ�������ʹ�������߷��͡������Ʒ���������һ�ӻ���$n$l",
	"dodge": 10,
	"force": 280,
	"lvl"  : 30,
	"damage_type": "����"
]),
([      "action": "$Nʹ����������Ӱ������������һ��������$n������ȴ������Ϣ��������$n��$l",
	"dodge": 5,
	"force": 310,
	"lvl"  : 35,
	"damage_type": "����"
]),
([      "action": "$Nʹ�������߲�˿�֡���˫�۳ɲ���˼���Ť��״���ƹ�$n���мܣ�������$n��$l",
	"dodge": 0,
	"force": 340,
	"lvl"  : 40,
	"damage_type": "����"
]),
([      "action": "$N�������߰㻬����ʹ���������ΰ˷����Ӷ�����ʽ�Ŀ�϶�д��ݴ�����˫��һ������$n��$l",
	"dodge": 15,
	"force": 370,
	"lvl"  : 45,
	"damage_type": "����"
]),
([      "action": "$Nͦ��ֱ�������Ƹ߾٣����϶��£�һ�С�����̽ͷ��������$n��$l",
	"dodge": 5,
	"force": 410,
	"lvl"  : 52,
	"damage_type": "����"
]),
([      "action": "$Nʩչ���������졹������ǰһ�ܣ������ڰ���У�˫�ư������ף���Х�ػ���$n��ͷ��",
	"dodge": 20,
	"force": 450,
	"lvl"  : 60,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("����ڹ���򲻹����޷������������ơ�\n");

	if ((int)me->query_int() < 30)
		return notify_fail("������Բ������޷�������������ơ�\n");

	if ((int)me->query_con() < 20)
		return notify_fail("��ĸ��ǲ������޷������������ơ�\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
	
	if (!present("jinshe miji", me)) 
		return notify_fail("��ϰ���������Ʊ���һ���ж��������ܼ�����\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("youshen-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");

	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"youshen-zhang/" + action;
}