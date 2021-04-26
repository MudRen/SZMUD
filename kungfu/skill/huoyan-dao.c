// Code of ShenZhou
// huoyan-dao ���浶
// qfy, chage, paoshou Sept 26, 1996
// Ryu, 11/14/96.
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N˫���������˼��£�ͻȻ���һ����˫��һʽ����ľȡ�𡹣�����һƬ���˹���$n$l",
	"force" : 350,
        "dodge" : 70,
	"parry" : 10,
	"damage" : 30,
	"weapon": "����",
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "��ľȡ��"
]),
([	"action" : "������$Nʹ����ף�ڻ��桹��˫���籧Բ�������˴���һ���������ε���ն��$n��$l",
	"force" : 380,
        "dodge" : 60,
	"parry" : 10,
	"damage" : 35,
	"weapon": "���ε���",
        "damage_type" : "����",
	"lvl" : 12,
	"skill_name" : "ף�ڻ���"
]),
([	"action" : "$Nʹһʽ������ޱߡ����������д󿪴��أ�����Ʈ���鶯����$n£�������˵ĵ���֮��",
	"force" : 400,
        "dodge" : 70,
	"parry" : 10,
	"damage" : 40,
	"weapon": "���ε���",
        "damage_type" : "����",
	"lvl" : 24,
	"skill_name" : "����ޱ�"
]),
([      "action" : "$N�����ֻؾ���������һ�����������絶�и��䣬һʽ�������ֻء���Я��������$n������������", 
        "force" : 420,
        "dodge" : 60,
	"damage" : 45,
	"parry" : 10,
	"weapon": "����",
        "damage_type" : "����",
        "lvl" : 36,
        "skill_name" : "�����ֻ�"
]),
([	"action" : "ֻ��$N��ɫ���أ�ʩչ��˫�����桹��˫�ƻ����Ƴ����������Ƶ�������ȻֱϮ$n��$l",
	"force" : 430,
	"parry" : 10,
        "dodge" : 50,
	"damage" : 50,
	"weapon": "����",
        "damage_type" : "����",
	"lvl" : 48,
	"skill_name" : "˫������"
]),
([	"action" : "$N���Ц��ʹ������ɽ�𺣡�������΢�࣬���ƴ���״�����Ю���ɼ��ȵľ�������$n",
	"force" : 450,
        "dodge" : 40,
	"parry" : 10,
	"damage" : 60,
	"weapon": "����",
        "damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "��ɽ��"
]),
([      "action" : "$N��������­ʽ������һչ���׷��ȡ�������һ��������$n��$l��ȥ",
        "force" : 480,
        "dodge" : 30,
	"parry" : 10,
	"damage" : 70,
	"weapon": "���ε���",
        "damage_type" : "����",
        "lvl" : 72,
        "skill_name" : "�׷���"
]),
([	"action" : "$NԾ��һʽ���������������������������ڵľ�����ס$n�����ӣ����ƽ��һ��ն��$n����",
	"force" : 530,
        "dodge" : 40,
	"parry" : 10,
	"damage" : 90,
	"weapon": "����",
        "damage_type" : "����",
	"lvl" : 84,
	"skill_name" : "��������"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20)
		return notify_fail("���������������򲻹����޷�ѧ���浶��\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������̫�����޷������浶��\n");
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
	level = (int)me->query_skill("huoyan-dao", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

//	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������浶��\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("huoyan-dao", 1) >= 50 )
                return __DIR__"huoyan-dao/" + action;
}
