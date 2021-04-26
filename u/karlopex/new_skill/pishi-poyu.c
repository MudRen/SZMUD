// Code of ShenZhou
// pishi-poyu.c ��ʯ����ȭ
// qfy September 28, 1996.

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʩչ������ʽ��������΢������ȭ���ƺ���һҾ��ͻȻ������ǰ��̽������$n$l",
        "force" : 150,
        "dodge" : 5,
	"parry" : 10,
        "lvl" : 0,
        "skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N�����鸧ʹ����ʯ���쾪������ȭ��ಡ���һ�����Ʒ����ʹ�����������$n��$l",
	"force" : 200,
        "dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"skill_name" : "ʯ���쾪",
	"damage_type" : "����"
]),
([	"action" : "$N�����������ǰ����˫�ơ����ź��š���������������֮������������$n",
	"force" : 240,
        "dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
	"skill_name" : "���ź���",
        "damage_type" : "����"
]),
([	"action" : "$N�ڿշ���һʽ��ǧ��׹�ء�������$n��������͵���ȭ��ȭ����������ɽ",
	"force" : 280,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
	"skill_name" : "ǧ��׹��",
        "damage_type" : "����"
]),
([	"action" : "��Ȼ$nת��$N���$Nһʽ�����������������д����ı��Է���һȭѸ�ݻػ�",
	"force" : 320,
        "dodge" : 10,
	"parry" : 15,
	"lvl" : 38,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�����һ�С����ֿβ�������嵽$n��ǰ��ץ�����д�Ѩ������$n������",
	"force" : 360,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 45,
	"skill_name" : "���ֿβ",
        "damage_type" : "����"
]),
([	"action" : "$N˫ȭ������ʹ��������֡�����������ȭӰ����ɽ������ظ���$n��������",
	"force" : 400,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 55,
	"skill_name" : "�����",
        "damage_type" : "����"
]),
([	"action" : "$Nȭ�������Ƶ磬һʽ����ʯ���񡹣����𻢻�ȭ�磬����ǧ���ı�ֱ����$n$l",
	"force" : 450,
        "dodge" : 15,
	"parry" : 15,
	"lvl" : 65,
	"skill_name" : "��ʯ����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ʯ����ȭ������֡�\n");
	if ((int)me->query_skill("zixia-gong", 1) < 20)
		return notify_fail("�����ϼ����򲻹����޷�ѧ��ʯ����ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�����ʯ����ȭ��\n");
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
	level   = (int) me->query_skill("pishi-poyu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������ʯ����ȭ��\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hunyuan-zhang/" + action;
}
