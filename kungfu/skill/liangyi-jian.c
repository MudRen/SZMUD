// Code of ShenZhou
// liangyi-jian.c ������ �����ǽ���
// by maco

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N��������������б����һ�С����ɷ��١�����â�Ӱ����ֱк��������$n��$lն��",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "skill_name" : "���ɷ���",
        "damage_type" : "����"
]),
([      "action" : "$N���к��䣬����бб��ʹ��һʽ�����ɻ�������·ȫ��б�ƣ�Ʈ�����ף�ż���ּ���һ����ʽ����$n����׽��",
        "force" : 140,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 20,
        "skill_name" : "���ɻ�",
        "damage_type" : "����"
]),
([      "action" : "$N����ƽ�̶������泯���ң�һ�С���Įƽɳ����$w�Ͻ�����ãĪ�⣬�����ޱߵش���$n��$l",
        "force" : 160,
        "dodge" : -5,
        "damage" : 15,
        "lvl" : 40,
        "skill_name" : "��Įƽɳ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��$w��һʽ������ɽ١�������Ѹ�����ף�$w�����������죬������$n$l�Ѳ������",
        "force" : 220,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 60,
        "skill_name" : "����ɽ�",
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ת��ʹ��һ�С����տ��㡹�����ȳ��ȣ�ֱ��$n$l��������Ԩͣ���ţ����ƹ�׾��ʵ���̲��������",
        "force" : 280,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 80,
        "skill_name" : "���տ���",
        "damage_type" : "����"
]),
([      "action" : "$N�ὣ��������һ�С�ѩӵ���š��ƣ���Ȼ����һ����ɭɭ�Ľ��⣬��$n��������ס",
        "force" : 340,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 100,
        "skill_name" : "ѩӵ����",
        "damage_type" : "����"
]) ,
([      "action" : "$N����бָ��أ�ʹһ�С�ľҶ������������һ�������Ⱪ�������������죬ת˲��������$n�����߰˴�Ҫ��",
        "force" : 380,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 120,
        "skill_name" : "ľҶ����",
        "damage_type" : "����"
]) ,
([      "action" : "$Nб��һ����һ�С��ͱڶ��ơ������Ƴ����վ����������ԣ�$w����$n��$l�����������֮�У������������������仯",
        "force" : 450,
        "dodge" : 20,
        "damage" : 70,
        "lvl" : 100,
        "skill_name" : "�ͱڶ���",
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
        if( (int)me->query_skill("xuantian-wuji", 1) < 20 )
                return notify_fail("��������޼����̫ǳ��\n");
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������������\n"); 
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
        level   = (int) me->query_skill("liangyi-jian",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
		  return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
      object weapon;
        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("jingli") < 50 )
                return notify_fail("��ľ������������ǽ�����\n");

        if( me->query_skill("liangyi-jian", 1) < 100 )
                me->receive_damage("jingli", 35);
        else
                me->receive_damage("jingli", 20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liangyi-jian/" + action;
}


