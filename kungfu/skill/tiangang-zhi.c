// Code of ShenZhou
// tiangang-zhi.c ���ָѨ��

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ��������ġ����缹����������������֮�У�ָ������Ծˮ������$n��$l",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 0,
        "weapon": "ָ��",
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N����б�٣�һʽ��������̶������ָ���ұ۹�����ָ��$n������·Ҫ��",
        "force" : 300,
        "dodge" : 15,
        "lvl" : 10,
        "weapon": "ָ��",
        "skill_name" : "������̶",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����߾��ɡ���ǰ��Ϊ��ͷ���������ͷ��һǰһ�����$n��$l",
        "force" : 400,
        "dodge" : 15,
        "lvl" : 20,
        "skill_name" : "���߾���",
        "damage_type" : "����"
]),
([      "action" : "$N����������ԣ�����ǰ����һʽ��������ɽ������ָ��ת������$n��$l",
        "force" : 450,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 30,
        "skill_name" : "������ɽ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ������������������������������ָ�ڷ�ǰָ������㼱��$n��$l",
        "force" : 500,
        "dodge" : 30,
        "damage": 35,
        "lvl" : 40,
        "weapon": "ָ��",
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���ֳŵأ�һʽ���ض�ɽҡ�����������嵽$n��ǰ������$n������·Ҫ��",
        "force" : 500,
        "dodge" : 35,
        "damage": 40,
        "lvl" : 60,
        "weapon": "ָ��",
        "skill_name" : "�ض�ɽҡ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��ˮ�����¡�������ǰ�ƣ�����һ����ǽ��ָ�����ƶ���������$n��$l",
        "force" : 550,
        "dodge" : 45,
        "damage": 50,
        "lvl" : 80,
        "weapon": "ָ��",
        "skill_name" : "ˮ������",
        "damage_type" : "����"
]),
([      "action" : "$N˫ָ���ɣ�һʽ��̩ɽѹ������ָ���û���һ��̫��Ȧ����̩ɽ����$n��ͷѹ��",
        "force" : 550,
        "dodge" : 50,
        "damage": 40,
        "lvl" : 100,
        "skill_name" : "̩ɽѹ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ָѨ��������֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
                return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ���ָѨ����\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷������ָѨ����\n");
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

	if( me->query_temp("tgz_attack") )
		return ([
			"action": "$N"+ me->query_temp("weapon_name") +
				"���˦��������ʳ�ж�ָ��$n������ȥ��һ��"+ chinese_number(3+random(7))
				+"ָ��ȫ�Ƕ���$pͷ����ǰ����Ѩ",
			"force" : 500,
			"dodge" : 15,
			"damage": 45,
        		"damage_type" : random(2)?"����":"����",
			"weapon": random(2)?"ָ��":"ָ��"
			]);

        level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("����������������ָѨ����\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}
