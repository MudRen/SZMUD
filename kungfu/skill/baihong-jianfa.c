// Code of ShenZhou
// baihong-jianfa �׺罣��
// by wsky

#include <ansi.h>
#include <combat.h>

inherit SKILL;
#include "/kungfu/skill/force_list.h"

mapping *action = ({
([      "action":"$N������ȭ�����ֽ������飬һ���ɡ��׺�һ�֡���$w����һ����â������$n��$l",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "�׺�һ��",
        "damage_type":  "����"
]),
([      "action":"$Nʹ��һ�С�ӥ���������������Ʈ������$w�͵�����$n��$l",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "ӥ������",
        "damage_type":  "����"
]),
([      "action":"$N����һ�Σ���Ȼһʽ��������ӿ������$w������粨�Σ�Ю��һ�󾢷���$nɨȥ",
        "force" : 250,
        "dodge" : 10,
        "parry" : 10,
        "damage": 60,
        "lvl" : 30,
        "skill_name" : "������ӿ",
        "damage_type":  "����"
]),
([      "action":"$Nһ����[������һ�٣��漴������$w���һ���⻷��һ�С������޹⡹������ϵĻҳ�ɨ$n��$l",
        "force" : 380,
         "dodge" : 15,
        "parry" : 15,
        "damage": 75,
        "lvl" : 60,
        "skill_name" : "�����޹�",
        "damage_type":  "����"
]),
([      "action":"$N��ת���ӣ��ƺ���Ҫ���ܣ���Ȼ����һת��ʹ��һ�С����ֽ��������⻯�������ǹ�����$n��$l",
        "force" : 220,
        "dodge" : 8,
        "parry" : 8,
        "damage": 65,
        "lvl" : 65,
        "skill_name" : "���ֽ�",
        "damage_type":  "����"
]),
([      "action":"$N������һ�����������Ž�����һ�С������㺣������$w�����ü�����â����$n��$l",
        "force" : 350,
                  "dodge" : 10,
        "parry" : 10,
        "damage": 65,
        "lvl" : 70,
        "skill_name" : "�����㺣",
        "damage_type":  "����"
]),
([      "action":"$N�����������࣬һ�С���ӥ���衹���ӳ�����$w��ƮȻ����$n��$l",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 75,
        "skill_name" : "��ӥ����",
        "damage_type":  "����"
]),
([      "action":"$N���־�$w����������һ�ڣ�һ�С���˪ѩ�꡹��$w�������㺮������$n",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 80,
        "skill_name" : "��˪ѩ��",
        "damage_type":  "����"
]),
([      "action":"$N��������ȭ�����һ�У�ͻȻ���纮˪���ӳ�����$w����$n��$l����һ�С���ѩ��ɽ��",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 85,
        "skill_name" : "��ѩ��ɽ",
        "damage_type":  "����"
]),
([      "action":"$N����$wһָ������¶��΢΢��Ц�ݣ��������ٵ�����ȫ��һ�С��׺��������$w���������â����������$n��$l",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 90,
        "lvl" : 100,
        "skill_name" : "�׺����",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenghuo-xuanming", 1) < 10)
                return notify_fail("���ʥ����ڤ�����̫ǳ��\n");
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
        	  level   = (int) me->query_skill("baihong-jianfa",1);
	          for(i = sizeof(action); i > 0; i--)
                  if(level > action[i-1]["lvl"])
                  return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ����������׺罣����\n");
        me->receive_damage("jingli", 25, "����͸֧��������");
        return 1;
}

string perform_action_file(string action)
{
                  return __DIR__"baihong-jianfa/" + action;
}

