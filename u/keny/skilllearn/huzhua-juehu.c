// Code of ShenZhou
// ��צ������ huzhua-juehu.c

inherit SKILL;

mapping *action = ({
([	"action" : 
"$N˫��һ�֣�ʹ��һʽ������������������������ת��������Ϣ������$n��$l",
	"force" : 320,
	"dodge" : 20,
	"damage": 35,
	"lvl"   : 0,
	"skill_name" : "��������" ,		
	"damage_type" : "����"
]),
([	"action" : 
"$Nһ����Х����ָ��ţ�ʹ��һʽ�����ɻ�Ѫ����צʽ�й�ֱ����������ƥ�ص���$n��$l",
	"force" : 360,
	"dodge" : 20,
	"damage": 40,
	"lvl"   : 15,
	"skill_name" : "���ɻ�Ѫ" ,		
	"damage_type" : "ץ��"
]),
([	"action" : 
"$N˫צ���ͣ��������ף�һʽ������ҹ������˫�ֽ���ʲ�����ҹ�����̰�����$n��$l",
	"force" : 400,
	"dodge" : 25,
	"damage": 50,
	"lvl"   : 30,
	"skill_name" : "����ҹ��" ,		
	"damage_type" : "ץ��"
]),
([	"action" : 
"$N�����𴦣�˫צ�������ɣ�һʽ����ȸ��ʬ����ʮָ���������Ʒ���������Ѹ�����׵ز���$n��$l",
	"force" : 450,
	"dodge" : 25,
	"damage": 65,
	"lvl"   : 45,
	"skill_name" : "��ȸ��ʬ" ,		
	"damage_type" : "ץ��"
]),
([	"action" : 
"$N���η���������»�������һ�С�������������צʽ��ز�պݣ����������ץ��$n��$l",
	"force" : 500,
	"dodge" : 30,
	"damage": 85,
	"lvl"   : 60,
	"skill_name" : "��������" ,		
	"damage_type" : "ץ��"
]),
([	"action" : 
"$N��Ϣ���£���ʽչ����һ�С��׻�������������ʵ�죬˫��΢΢����������һ�ɼ�����ǰ������֮��Ϯ��$n��$l",
	"force" : 560,
	"dodge" : 40,
	"damage": 75,
	"lvl"   : 75,
	"skill_name" : "�׻�����" ,		
	"damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ�����ֱ�����֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 100)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ��צ�����֡�\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������̫�����޷�����צ�����֡�\n");
	if ((int)me->query("shen") < (int)me->query_skill("huzhua-juehu",1)*1000)
		return notify_fail("�����������̫�ͣ��޷�����צ�����֡�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("huzhua-juehu",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������צ�����֡�\n");
        if ((int)me->query("shen") <(int)me->query_skill("huzhua-juehu",1)*1000)
                return notify_fail("�����������̫�ͣ�����צ�����ֻ��߻���ħ��\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

