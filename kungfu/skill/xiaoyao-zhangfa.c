// Code of ShenZhou
// xiaoyao-zhangfa
// ��ң�Ʒ���

inherit SKILL;

mapping *action = ({
([      "action": "ֻ����Ӱһ����$N˫��ƽƽ�ᵽ��ǰ��һǰһ�������$n��$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "����"
]),
([      "action": "$NͻȻ����һת��Ʈ��$n����������͵ػ���$n��$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "����"
]),
([	"action": "$N������һת����һת�����о������䣬˫������������$n��$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "����"
]),
([	"action": "$N΢΢һЦ���ƺ��Ѿ�������$n�������������������ŷ�������$n��$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$N�����������ĵ���΢΢����һ����Х��˫�������������$n��$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$N�˺�һ�������Ʋ�����������ƮƮ������$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$N�͵�Ծ�������ڿ���һת�����ƴӲ����ܵĽǶ���$n�Ƴ�",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "����"
]),
([	"action": "$N����������һ������˫�ƾ���һ��һ��������$n��$l",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "����"
]),
([	"action": "$N���һ�����������ĵ���$n��$l��������",
	"dodge": -20,
	"parry": -20,
	"force": 230,
	"damage_type": "����"
]),
([	"action": "$N���ӵ������һת������һ�������Ʒɿ�ذ���$n��$l",
	"dodge": -10,
	"parry": 20,
	"force": 160,
	"damage_type": "����"
]),
([	"action": "$N˫ü΢����Ϻ�ɫһ�֣����ƻ���$n��$l�����������Ƴ���������������һ��",
	"dodge": -20,
	"parry": 30,
	"force": 250,
	"damage_type": "����"
]),
([	"action": "$nֻ����ǰһ����$N����һ�ڣ������������ϻ���$n��$l",
	"dodge": -25,
	"parry": 1,
	"force": 320,
	"damage_type": "����"
]),
([	"action": "$N����һƮ���������ɣ�������Σ����ư���$n��$l",
	"dodge": -15,
	"parry": 40,
	"force": 200,
	"damage_type": "����"
]),
([	"action": "$N��һƮ����һ�����½��ڷ���΢΢Ʈ��������ڱ�������৵û���$n��$l",
	"dodge": -10,
	"parry": 40,
	"force": 220,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ң�Ʒ�������֡�\n");
	if ((int)me->query_skill("shenhuo-xuanming", 1) < 20)
		return notify_fail("���ʥ����ڤ����򲻹����޷�����ң�Ʒ� ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ң�Ʒ���\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("���������������ң�Ʒ���\n");
	me->add("jingli", -30, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"xiaoyao-zhangfa/" + action;
}
