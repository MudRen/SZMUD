// Code of ShenZhou
// jueming-tui.c

inherit SKILL;

mapping *action = ({
([      "action": "$n���ҽŹ���$N������̣�$N��űܿ�$n��â��һ�С��ڻ���ɽ����\n"
                  "Ѹ�������������߻�$n��$l��",
        "dodge": 10,
        "force": 200,
        "damage_type": "����"
]),
([      "action": "$n��ȭ��$Nͷ����$N���������ͬʱ���ҽ��͵�$n����������Գ��֦����\n"
                  "ͻȻ������������߻�$n$l��",
        "dodge": 25,
        "force": 180,
        "damage_type": "����"
]),
([      "action": "$N��ȭ�ò�$nȭͷ���ҽ��ڲ�Ȼ�$n���ֹǣ�һ�С���β���֡�\n"
                  "�����ȹ���$n$l",
        "dodge": -40,
        "force": 120,
        "damage_type": "����"
]),
([      "action": "$N���ҽŹ���$n�������̣�ͬʱ�ҹ���ͻȻ��ɨ$n������һ�С�����Ҷ��",
        "dodge": -50,
        "force": 160,
        "damage_type": "����"
]),
([      "action": "$n����ȭ�ͻ�$N�沿��$N����������ȹ���$n�󲿣�һ�С����˷�������\n"
                  "��Ϊ��������$n��$l",
        "dodge": 60,
        "force": 200,
        "damage_type": "����"
]),
([      "action": "$Nͻ�����ȵ���$n�ɲ������������򡹣������ٱ��������߻�$n֮$l",
        "dodge": 70,
        "force": 250,
        "damage_type": "����"
]),
([      "action": "$N���ҽŹ���$n�����ʹ����˳�糶�졹��˳�Ʊ�Ϊ���ȣ��൹��ɨ$n$l",
        "dodge": 80,
        "force": 100,
        "damage_type": "����"
]),
([      "action": "$N���ҽŵ���$n������һ�С�Ұ���㡹������֮�ȼ���Ϊ�����ȣ���������$n$l",
        "dodge": 90,
        "force": 300,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return  usage=="kick"; }
int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
//        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//                return notify_fail("�������ȱ�����֡�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("��Ķ����󷨻������޷�ѧ�����ȡ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷��������ȡ�\n");
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
                return notify_fail("������������������ȡ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueming-tui/" + action;
}
