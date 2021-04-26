// Code of ShenZhou
// shexing-diaoshou ���ε���
// qfy August 21, 1996
// be converted to lingshe-quan ����ȭ��
// kane 31/8/98

inherit SKILL;
mapping *action = ({
([	"action" : "$N���ƻ��أ��ұ�΢�������Σ��������⼲�죬һʽ�����߳���������$n��$l",
	"force" : 150,
        "dodge" : 10,
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "���߳���"
]),
([	"action" : "$Nʹ�����������㡹��˫����$nץȥ��ͬʱ��������Ϣ��һ������$n��$l",
	"force" : 180,
        "dodge" : 10,
        "damage_type" : "����",
	"lvl" : 10,
	"skill_name" : "��������"
]),
([	"action" : "ֻ��$N�����ڵأ�ͻȻ������ʹ��һ�С�������Ӱ������ݺݵ�ץ��$n��$l",
	"force" : 220,
        "dodge" : 15,
        "damage_type" : "ץ��",
	"lvl" : 20,
	"skill_name" : "������Ӱ"
]),
([	"action" : "$Nһʽ����ӥ��������˫�ִ���˻˻�ƿ�֮��������Ѹ�ٵؾ���$n����Ҫ������",
	"force" : 260,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 38,
	"skill_name" : "��ӥ����"
]),
([	"action" : "$N˫�ֻ����лó������Ӱ��һ�С�������ӿ������������������ǵ�����$n",
	"force" : 290,
        "dodge" : 10,
        "damage_type" : "����",
	"lvl" : 46,
	"skill_name" : "������ӿ"
]),
([      "action" : "$N���䲻���ʹһʽ���������š�������ʳ����ָ΢�֣���������$n��$l��ͱ",
	"force" : 320,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 55,
        "skill_name" : "��������"
]),
([	"action" : "ͻ��$N˫�������޹ǵ������ţ�ʹ�����������񡹲�ס$n���ұ�ȴ���ĵشӲ���˼�鴦Ĩ��$n��$l",
	"force" : 350,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 65,
	"skill_name" : "��������"
]),
([      "action" : "$N˫��һ�ʣ����䲻���ʹһʽ���������󡹣�˫�ַ�����˼��һŤ������$n��$l",
        "force" : 390,
        "dodge" : 0,
        "damage_type" : "����",
        "lvl" : 75,
        "skill_name" : "��������"
]),
([      "action" : "$N�ֽŲ�̧��ʹ��һʽ������������������հ��𣬷���ײ��$n��$l",
        "force" : 420,
        "dodge" : 5,
        "damage_type" : "����",
        "lvl" : 85,
        "skill_name" : "��������"
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="shentuo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ��������֡�\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ����ȭ����\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ȭ����\n");
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
	level = (int)me->query_skill("lingshe-quan", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ����\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
