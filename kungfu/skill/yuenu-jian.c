// Code of ShenZhou
// yuenu-jian.c ԽŮ����
// ȡ�ģ������Ӣ�۴�����СӨ + ��ԽŮ��������
// maco

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$NʩչС����Ų֮����һ�С���¶�Ὥ�������������趯��$w����$n$l",
        "force" : 100,
        "dodge" : 30,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "��¶�Ὥ",
        "damage_type": "����"
]),
([      "action": "$N����һ�С����ճ��ա��������⼱�������������$w��$n��ߴ�����ȥ�����в���Ҫ��",
        "force" : 120,
        "dodge" : 20,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "���ճ���",
        "damage_type": random(2)?"����":"����"
]),
([      "action" : "$N����һ�㣬�������飬һ�С����ͷ��������΢�࣬$w����$n$l�������â�������ֺ���׼�����Ǿ�΢����",
        "force" : 150,
        "dodge" : 5,
        "damage" : 20,
        "lvl" : 20,
        "skill_name" : "���ͷ",
        "damage_type": "����"
]),
([      "action" : "$Nչ��������������$n�������ת����$w�ݳ���һ�С�֦����Գ����Ծ������������ƽ����ٿȻ�ؽ�����",
        "force" : 180,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 30,
        "skill_name" : "֦����Գ",
        "damage_type" : "����"
]),
([      "action" : "$N������ת��һ��������̽���������̲��������̲��ܣ���������һŲ����Ȼ�ƿ���ߣ�����$wֱ����$n",
        "force" : 200,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 40,
        "skill_name" : "����̽��",
        "damage_type" : "����"
]),
([      "action" : "$N��������������������ߣ�������ǰ��$w��̽��ն�ԡ����ط��²壬����$n���̣�������Ϊ����",
        "force" : 300,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 50,
        "skill_name" : "̽��ն��",
        "damage_type" : random(2)?"����":"����"
]),
([      "action" : "$N��ϥһ�ͣ��������ţ�һ�С�������ԡ���ˢ��һ����$w��������",
        "force" : 350,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 60,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$NȦת$w��������Ϊǰ�����������Ž���������ƽ��˳�⣬�ὣ��$n���ƣ��ڷ���֮�����̸��ӱ仯�����ǡ�ʮ���ĥ��֮��",
        "force" : 400,
        "dodge" : 0,
        "damage" : 100,
        "lvl" : 70,
        "skill_name" : "ʮ���ĥ",
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for( i = sizeof(action)-1; i >= 0; i-- )
                if( level >= action[i]["lvl"] )
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("yuenu-jian", 1);

        for( i = sizeof(action); i > 0; i-- )
                if( level > action[i-1]["lvl"] )
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("jingli") < 50 )
                return notify_fail("��ľ���������ԽŮ������\n");

                me->receive_damage("jingli", 20);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yuenu-jian/" + action;
}
