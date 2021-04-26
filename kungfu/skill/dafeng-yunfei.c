// Code of ShenZhou
// dafeng-yunfei
// ����Ʒ���

inherit SKILL;

mapping *action = ({
([      "action": "ֻ��$N����һ�һ�з�ƽ�˾�������$n$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
	"damage": 10,
	"skill_name": "��ƽ�˾�",
        "damage_type": "����"
]),
([      "action": "$N˫��ƽ����ǰ�������ֺ�Ȼ�ֱ���$n������·��ȥ������һ�з�����ɢ",
        "dodge": -15,
        "parry": -20,
        "force": 180,
	"damage": 20,
	"skill_name": "������ɢ",
        "damage_type": "����"
]),
([	"action": "$Nʹ��һ�з紵���˫�ֱ��Ī�⣬��ǰ�������㹥��$n����ҪѨ",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage": 30,
	"skill_name": "�紵���",
	"damage_type": "����"
]),
([	"action": "$N����Ʈ�죬˫�ַ������£�һ�з���Ʈҡ����$n��֪�÷��δ��Ǻ�",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage": 40,
	"skill_name": "����Ʈҡ",
	"damage_type": "����"
]),
([	"action": "$N���ƺ���������������������������$n��Χ���У���һ�з�����",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage": 50,
	"skill_name": "������",
	"damage_type": "����"
]),
([	"action": "$Nһ�з绨ѩ�£�˫��Ʈ���޷�����Ͷ��Ե��$n�Ǿ�ȫ��$N�ھ���Χ�������˱�",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"skill_name": "�绨ѩ��",
	"damage": 60,
	"damage_type": "����"
]),
([	"action": "$N˫��������㹥��$n$l����$n���д��ֲ������ų�һ���亹",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage": 70,
	"skill_name": "��۵糸",
	"damage_type": "����"
]),
([	"action": "$N���δ���˫�ֺ��Ϻ��£�������ң�һ�з��Ʊ�ã��˵���Ʈ���޷���������Ʒ��ַ��ӵ����쾡�£�$n��ʱ��֪����",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage": 80,
	"skill_name": "���Ʊ��",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="riyue-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������Ʒ��ֱ�����֡�\n");
	if ((int)me->query_skill("shenhuo-xuanming", 1) < 20)
		return notify_fail("���ʥ����ڤ����򲻹����޷�������Ʒ��� ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������Ʒ��֡�\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("�����������������Ʒ��֡�\n");
	me->add("jingli", -30);
	me->add("neili", -5);
	return 1;
}

