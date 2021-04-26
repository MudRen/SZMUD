// Code of ShenZhou
// bagua-dao.c ���Ե�
  
inherit SKILL;
mapping *action = ({
([      "action" : "$N$wʹ�����Ե�������$n",
	"force" : 170,
	"dodge" : 15
	"parry" : 15
	"damage": 20
	"lvl" : 0,
	"skill_name" : "���Ե�",
	"damage_type" : "����"
]),
	// more actions
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenghuo-xuanming",1) < 20)
		return notify_fail("���ʥ����ڤ�����δ�������޷���ϰ���Ե���\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])

	return action[i]["skill_name"];
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
	level   = (int) me->query_skill("bagua-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
	
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ��������������Ե���\n");
	me->receive_damage("jingli", 30, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"bagua-dao/" + action;
}
