// Code of ShenZhou
// yanxing-dao.c ���е���

inherit SKILL;

mapping *action = ({
([	"action" : "$NĬ����־�����Ѹ������$n�Ĺ��ƣ�$wͬʱ������$n��$l�ӳ�",
	"force" : 120,
	"dodge" : 15,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N�������ã�һ�С����־���������$wֱ�������䲻��ش���$n���沿",
	"force" : 130,
	"dodge" : 10,
	"damage": 20,
	"lvl" : 5,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N���������־�����$w�ȷ�������Ԥ�ȶ�ס��$n��ͼ��������ʽ",
	"force" : 140,
	"dodge" : 15,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N��ʾ������һ�С����־�������$n����Ϊ��ʱ���͵ػӶ�$w��$n��$lնȥ",
	"force" : 160,
	"dodge" : 15,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "���־�",
	"damage_type" : "����",
]),
([	"action" : "$N�������־������������ã�������ߣ���$n׷�������䲻������ͻ�",
	"force" : 180,
	"dodge" : 30,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N����ԵУ���վ��԰��һ�С����־�����$w�����޶����ƹ����أ���$n�����ʴ�",
	"force" : 210,
	"dodge" : 25,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N���̽�־���������������$n�Ĺ���������$w���ӣ���$n��$l��ȥ",
	"force" : 240,
	"dodge" : 15,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "̽�־�",
	"damage_type" : "����"
]),
([	"action" : "$N���󡸱��־���������$w��ն����һ�н�һ�в�ͣ����$n��$l�͹�",
	"force" : 280,
	"dodge" : 25,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N���氵�գ�һ�С����־���������էչ��ָ�ϴ��£�ָ��������ɱ������",
	"force" : 330,
	"dodge" : 25,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
([	"action" : "$N���ء����־������������������д��ң�$n��ʱ����ʧ�룬���ִ���",
	"force" : 380,
	"dodge" : 30,
	"damage": 80,
	"lvl" : 70,
	"skill_name" : "���־�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="huifeng-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
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
	level   = (int) me->query_skill("yanxing-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������������е�����\n");
	if (me->query_skill("yanxing-dao", 1) < 100)
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yanxing-dao/" + action;
}

