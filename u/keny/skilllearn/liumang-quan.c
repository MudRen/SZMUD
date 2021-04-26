//��ң��(Abian)
// liumang-quan.c -��åȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$N�ڵ���������ȥ��ץס��$n��С�ȣ�ʹ����һ�С������ˮ���������Ĵ���$n��$l",
	"force" : 200,
        "dodge" : 15,
        "parry" : 30,
	"damage": 50,
	"lvl" : 0,
	"skill_name" : "�����ˮ",
        "damage_type" : "����"
]),
([	"action" : "$N����$n�ı��ϣ����ص�ʹ�ˡ����ú��ԡ�,$nʹ�Ľ���һ����$N������ȭͷȥ��$n��$l",
	"force" : 300,
        "dodge" : 30,
        "parry" : 30,
	"damage": 100,
	"lvl" : 20,
	"skill_name" : "���ú���",
        "damage_type" : "����"
]),
([	"action" : "$N���ޡ�������һ��̵����;Ͷ�ݺݵ���$n��$lʹ���ˡ����ڲ����֡�",
	"force" : 500,
        "dodge" : 25,
        "parry" : 30,
	"damage": 200,
	"lvl" : 40,
	"skill_name" : "���ڲ�����",
        "damage_type" : "ҧ��"
]),
([	"action" : "$N��������ס��ȭͷ������ˡ�����ҡ�ڡ���ȭͷ����$n��$l��ȥ��",
	"force" : 600,
        "dodge" : 100,
        "parry" : 100,
	"damage": 400,
	"lvl" : 60,
	"skill_name" : "����ҡ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wrestling"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����å������֡�\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("����ڹ�̫�����޷�ѧ��åȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����åȭ��\n");
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
	level   = (int) me->query_skill("liumang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������åȭ��\n");

        if( (int)me->query_skill("force", 1) < 5
        &&  (int)me->query_skill("cuff", 1) < 5
        &&  (int)me->query_skill("parry", 1) < 5
        &&  (int)me->query_skill("dodge", 1) < 5 )
                return notify_fail("û��һ�㹦����ӣ�Ҫ��������åȭ��\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

