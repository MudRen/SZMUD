// Code of ShenZhou
// wuxing-quan for npc

inherit SKILL;

mapping *action = ({
([	"action" : "$N����һԾ��һʽ����ӥ���á�������»���ץ��$n��$l",
	"force" : 180,
        "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "��ӥ����",
        "damage_type" : "ץ��"
]),
([	"action" : "$N��ָ���ţ�һ�С��������򡹣���ݺݵ�ץ��$n��$l",
	"force" : 200,
        "dodge" : 10,
	"lvl" : 8,
	"skill_name" : "��������",
        "damage_type" : "ץ��"
]),
([	"action" : "$N��һ���������ʽ��ʹһ�С��ڻ�͵�ġ�������һȭ��$n��$l��ȥ",
	"force" : 220,
        "dodge" : 5,
	"lvl" : 15,
	"skill_name" : "�ڻ�͵��",
        "damage_type" : "����"
]),
([	"action" : "$N˫��������ʹ�С������̸��������Ź���$n��$l",
	"force" : 160,
        "dodge" : 10,
	"lvl" : 14,
	"skill_name" : "�����̸�",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С�ѩ���Ƕ�����˫��ǰ̽���͵�����$n��$l",
	"force" : 200,
        "dodge" : 5,
	"lvl" : 13,
	"skill_name" : "ѩ���Ƕ�",
	"damage_type" : "����"
]),
([	"action" : "$N��ס$n�ֱۣ�һ�š�˳��ǣ�򡹣�˳�ƽ�$n��ǰһ����˫ȭ����$n��$l",
	"force" : 160,
        "dodge" : 10,
	"lvl" : 12,
	"skill_name" : "˳��ǣ��",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ����������ɽ��������˫�ۣ�����һ����ͷ�����Ĵ���$n��$l",
	"force" : 220,
        "dodge" : 5,
	"lvl" : 10,
	"skill_name" : "������ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�ã�һʽ��ͯ�Ӱݹ�������˫��һ����������$n��$l",
	"force" : 180,
        "dodge" : 14,
	"lvl" : 18,
	"skill_name" : "ͯ�Ӱݹ���",
        "damage_type" : "����"
]),
([	"action" : "$N���һ�У�ʹһ�С�Ҷ��͵�ҡ������䲻��ķ���ץ��$n��$l",
	"force" : 180,
        "dodge" : 14,
	"lvl" : 18,
	"skill_name" : "Ҷ��͵��",
        "damage_type" : "ץ��"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("���޷�������ȭ��\n");
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
	level   = (int) me->query_skill("wuxing-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	return notify_fail("�㲻��������ȭ��\n");
}

