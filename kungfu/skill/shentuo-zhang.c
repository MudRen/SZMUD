// Code of ShenZhou
// shentuo-zhang ����ѩɽ��
// kane 31/8/98

inherit SKILL;
mapping *action = ({
([	"action" : "$N˫��һ�棬ʹ��һ�С�������������������ת������Ʈ��������$n��$l",
	"force" : 250,
        "dodge" : 0,
        "damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N�������һ���������ƣ��������ͣ�ʹ��һʽ����Į���������$n��$l",
	"force" : 280,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 20,
	"skill_name" : "��Į����"
]),
([	"action" : "$N���ȷ��������������ף��������޵�����$n��$l������һ�С����տ��㡹",
	"force" : 300,
        "dodge" : 15,
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "���տ���"
]),
([	"action" : "$N���η�����һʽ�������˪������Ӱ�׷ɣ������ھ��Ѱ�$n������ͳͳ��ס",
	"force" : 350,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 38,
	"skill_name" : "�����˪"
]),
([	"action" : "$N���μ�ת�������һ�С����ճ�������ͷ�½��ϣ�ɲ�Ǽ��ֽ��빥������$n��$l",
	"force" : 350,
        "dodge" : 0,
        "damage_type" : "����",
	"lvl" : 46,
	"skill_name" : "���ճ���"
]),
([      "action" : "$N����һ����ʹ��һʽ��ѩ��ǧɽ��������������ŭ����ӿ����������$n��$l",
	"force" : 400,
        "dodge" : 0,
        "damage_type" : "����",
        "lvl" : 55,
        "skill_name" : "ѩ��ǧɽ"
]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="lingshe-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ѩɽ�Ʊ�����֡�\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ����ѩɽ�ơ�\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ѩɽ�ơ�\n");
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
	level = (int)me->query_skill("shentuo-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ѩɽ�ơ�\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
