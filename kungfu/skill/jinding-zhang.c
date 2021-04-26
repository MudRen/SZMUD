// Code of ShenZhou
// jinding-zhang.c ������

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N��$nңңһ�ϣ�һʽ��������̩����˫�ƴ󿪴��أ�����$n�Ľ���",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "������̩",
        "damage_type" : "����"
]),
([      "action" : "$N�溬΢Ц��һʽ���������项��˫���Ʋ����ƣ�ͬʱ����$nȫ�����",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage": 20,
        "lvl" : 10,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ������ơ���˫�ֻ��ƣ�һǰһ����ǰ���ƣ�����$n��$l",
        "force" : 260,
        "dodge" : 20,
        "parry" : 25,
        "damage": 15,
        "lvl" : 20,
        "skill_name" : "�����",
        "damage_type" : "����"
]),
([      "action" : "$N�������һʽ��������ɳ����˫����£���У�����$n������",
        "force" : 320,
        "dodge" : 20,
        "parry" : 25,
        "damage": 25,
        "lvl" : 40,
        "skill_name" : "������ɳ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ���׶���������˫����Ѹ�ײ����ڶ�֮�ƣ�����$n������̫��Ѩ",
        "force" : 400,
        "dodge" : 20,
        "parry" : 25,
        "damage": 35,
        "lvl" : 60,
        "weapon" : "�Ʒ�",
        "skill_name" : "�׶�����",
        "damage_type" : "����"
]),
([      "action" : "$Nŭ߳һ����һʽ���𶥷�⡹���������������Ƽ���$n�Ķ�����Ѩ",
        "force" : 450,
        "dodge" : 20,
        "parry" : 25,
        "damage": 40,
        "lvl" : 70,
        "skill_name" : "�𶥷��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����Ľ�ħ����˫�����÷��ã��ƶ��Ƕ��������缱����ʹ$n��������",
        "force" : 500,
        "dodge" : 15,
        "parry" : 20,
        "damage": 45,
        "lvl" : 80,
        "skill_name" : "���Ľ�ħ",
        "damage_type" : "����"
]),
([      "action" : "$N������Ƴ����ĳ���������һʽ������˻ġ��������ǵذ����$nӿȥ",
        "force" : 550,
        "dodge" : 30,
        "parry" : 20,
        "damage": 50,
        "lvl" : 100,
        "skill_name" : "����˻�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_str() < 25 && me->query("str") < 20 )
                return notify_fail("��ı������㣬�޷�ѧ�������ơ�\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ�����ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷��������ơ�\n");
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
        int i, jiali;
        int level   = (int) me->query_skill("jinding-zhang",1);
        mapping px_info;
	object victim, ob;

	// lasting effects of piaoxue
        ob = me->select_opponent();

        px_info = me->query_temp("piaoxue/usage_info");
        victim = me->query_temp("piaoxue/target");

        if ( objectp(victim) && ob == victim ) {
	    jiali=me->query("jiali");
	    if (jiali > px_info["neili_damage"]) 
		jiali = px_info["neili_damage"];
	    if (ob->query("neili") > 0) {
		message_vision(HIY "\n$n����͸$P��������ʵ��ֻ�ô����������ȫ������������\n" NOR, me, victim);
		ob->add("neili", -jiali);
	    } else {
		message_vision(HIY "\n$nһ�������᲻��������$P�Ʒ�ɨ�У��������ģ��������¡�\n" NOR, me, victim);
		ob->receive_damage("qi", jiali, me);
	    }
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/" + action;
}

