// Code of ShenZhou
// qianye-shou.c -����ǧҶ��

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ���Ϻ���𡹣�������Σ���������ͻȻ����$n�ı����Ѩ",
	"force" : 100,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "�Ϻ����",
	"damage_type" : "����"
]),
([	"action" : "$N����һ�Σ�һʽ����������������������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"force" : 110,
        "dodge" : 10,
	"lvl" : 10,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����������������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"force" : 130,
        "dodge" : 20,
	"damage": 5,
	"lvl" : 20,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�������У�����ֱ����һʽ�������Ӱ������Ʈ��������$n������",
	"force" : 160,
        "dodge" : 20,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "�����Ӱ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ��ˮ��׽�¡�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"force" : 200,
        "dodge" : 30,
	"damage": 15,
	"lvl" : 38,
	"skill_name" : "ˮ��׽��",
        "damage_type" : "ץ��"
]),
([	"action" : "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"force" : 250,
        "dodge" : 30,
	"damage": 20,
	"lvl" : 45,
	"skill_name" : "����ȥ��",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��ˮ�ݳ�û����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"force" : 310,
        "dodge" : 40,
	"damage": 25,
	"lvl" : 51,
	"skill_name" : "ˮ�ݳ�û",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ����������������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"force" : 380,
        "dodge" : 40,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������տա���ȭ���������֣��������ޣ�����������$n�ĵ���",
	"force" : 460,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 60,
	"skill_name" : "����տ�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo== "longzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ǧҶ�ֱ�����֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ǧҶ�֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ǧҶ�֡�\n");
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
	level   = (int) me->query_skill("qianye-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ǧҶ�֡�\n");

        if( (int)me->query_skill("sanhua-zhang", 1) < 90 )
                return notify_fail("���ɢ������Ϊ��������\n");

	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}

