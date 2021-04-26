// Code of ShenZhou
// yingxiong-sanzhao.c Ӣ������

inherit SKILL;

mapping *action = ({
([      "action" : "$nץס$N�ĺ󾱣�һ������$N����������ת����$n��Ҹ��ɦ��һ�ѣ�\n"
		   "$n��������������$N������ס$nҸ�£�����������ת��ץס$n��ڣ�����\n"
		   "����$n�����ӣ������Լ�ͷ��������ˤ��",
	"force" : 50,
	"dodge" : 5,
	"parry" : 10,
	"damage": 60,
	"lvl" : 0,
	"skill_name" : "����ٶ�",
	"damage_type" : "����"
]),
([      "action" : "$N�������ϣ�$n������̤ס$N�ĺ�����$N˫��һ����������ݣ�\n"
		   "�ұ�ȴ�������Ӷ�����ͻȻ��һ�������$n�Ŀ�����ȥ��ֻһ����\n"
		   "������ץס$n�ҽ����ף�������$nС����ȥ",
	"force" : 60,
	"dodge" : 20,
	"parry" : 20,
	"damage": 90,
	"lvl" : 10,
	"skill_name" : "³�����",
	"damage_type" : "����"
]),
([      "action" : "$N˫�۷��ڱ���ͻȻ˫��ʮָ���𣬸��ɰ���֮�Σ��������һײ\n"
		   "ʮָ��ץ��$n���ز���$n���һ����$NͻȻһ�������������Ծ��\n"
		   "˫��һ�֣��ѿ���$n��ͷ��ͬʱ˫�ְ�ָѹס$n̫��Ѩ��ʳָ��ü����ָ����",
	"force" : 100,
	"dodge" : 30,
        "parry" : 30,
	"damage": 110,
	"lvl" : 20,
	"skill_name" : "���ཱུ��",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

   int valid_combine(string combo) { return combo=="jueming-tui" ; }

int valid_learn(object me)
{
	if (me->query_int() < 25)
		return notify_fail("������Բ������޷�ѧӢ�����С�\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧӢ�����С�\n");
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
	level   = (int) me->query_skill("yingxiong-sanzhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
		return notify_fail("�������������Ӣ�����С�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

/*
string perform_action_file(string action)
{
	return __DIR__"yingxiong-sanzhao/" + action;
}
*/
