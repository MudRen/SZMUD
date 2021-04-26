//����ȭ
//cool 981010
inherit SKILL;

mapping *action = ({
([	"action" : "$N��һ��������΢��������һ����һ�С����°��졹��һȭֱͱ$n��$l",
	"force" : 170,
	"dodge" : 0,
       "parry" : 10,
	"lvl" : 0,
	"skill_name" : "���°���",
	"damage_type" : "����"
]),
([	"action" : "$N��������һЦ����ȭ�������ϣ���ȭƽƽ������һ�С��������졹���������$n",
	"force" : 200,
	"dodge" :-5,
       "parry" : 5,
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��$nһ����ȣ�ʹһ�С����羭�졹����ȭ�������漴��ȭ���ϣ�������������$n��$l",
	"force" : 230,
	"dodge" : 0,
       "parry" : 10,
	"lvl" : 30,
	"skill_name" : "���羭��",
	"damage_type" : "����"
]),
([	"action" : "$N�ƺ�һ����˫ȭ���Ϸֿ���һ�ǡ��ٻ����졹��ȭ�����ߣ�����ͬʱ����$n��$l",
	"force" : 260,
	"dodge" : 0,
       "parry" : 0,
	"lvl" : 45,
	"skill_name" : "�ٻ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nʩ����һ�����졹��һ�����һȭ��մ����ȭ��ֱ��$n��$l",
	"force" : 290,
	"dodge" : 0,
       "parry" : 5,
	"lvl" : 60,
	"skill_name" : "һ������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����Х��˫ȭ���������һ�С�ʯ���쾪����ȭ���ܲ�$n��ǰ������",
	"force" : 310,
	"dodge" : 10,
       "parry" : 10,
	"lvl" : 70,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([	"action" : "$Nŭ��һ������շ���һʽ��������ѡ���˫ȭ�Ӹ����£����봷��$n",
	"force" : 350,
	"dodge" : 20,
       "parry" : -10,
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$N�����Ц������������۷��裬һ�С��޷����졹��ȭ����������������$n��ȥ",
	"force" : 380,
	"dodge" : -5,
       "parry" : -10,
	"lvl" : 90,
	"skill_name" : "�޷�����",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="kunlun-zhang"; }


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ��������֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
                return notify_fail("��ġ������޼�������򲻹���\n");
        if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷���������ȭ����\n");
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

	level   = (int) me->query_skill("zhentian-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
		return notify_fail("�������������������ȭ����\n");
        me->add("jingli", -25);
        me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
return __DIR__"zhentian-quan/" + action;
}
