//YUNU-JIANFA (��Ů����)
//UPDATE BY SCATTER
//VERSION 1.0 BETA
//2001/07/30


// COLOR DEFINE
// RED - ��ɫ              HIR - ����ɫ
// GRN - ��ɫ              HIG - ����ɫ
// YEL - ����ɫ            HIY - ��ɫ
// BLU - ����ɫ            HIB - ��ɫ
// MAG - ǳ��ɫ            HIM - �ۺ�ɫ
// CYN - ����ɫ            HIC - ����ɫ
// WHT - ǳ��ɫ            HIW - ��ɫ



#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$Nһʽ"+HIY"����ǰ���¡�"+NOR"�����϶��£��������º�ա��ǹ��̵أ�����$wƮƮȻ����$n$l",
	"force" : 150,
        "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "��ǰ����",
	"damage_type":	"����"
]),
([	"action":"$Nʹ��"+HIG"�����ٰ��"+NOR"����̾һ����˫ü΢�壬����$w����һ����$w��ȻԾ��ٿ�Ļ��������ǹ⣬����$n��$l",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "���ٰ���",
	"damage_type":	"����"
]),
([	"action":"$N������Ȼ��һ��"+HIW"��ɨѩ��衹"+NOR"������$w�������Һ�ɨ��ȥ����Ȼ��������$n��$l����",
	"force" : 250,
    "dodge" : 10,
	"parry" : 10,
	"damage": 60,
	"lvl" : 15,
	"skill_name" : "ɨѩ���",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+MAG"������С�á�"+NOR"��һ����Σ����������ƣ���һ�ֳ�$wȴ��$n$l�����ӳ�����",
	"force" : 280,
    "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 25,
	"skill_name" : "����С��",
	"damage_type":	"����"
]),
([	"action":"$N����һ����һ��"+WHT"�����¶��ġ�"+NOR"��$w����ѩ�⣬��$n������ȥ",
	"force" : 220,
    "dodge" : 8,
	"parry" : 8,
	"damage": 70,
	"lvl" : 30,
	"skill_name" : "���¶���",
	"damage_type":	"����"
]),
([	"action":"$N�������ŵ���ǰһ̽���趯$w��ʹ��"+HIY"���رߵ��ס�"+NOR"����������$n����",
	"force" : 350,
        "dodge" : 10,
	"parry" : 10,
	"damage": 55,
	"lvl" : 35,
	"skill_name" : "�رߵ���",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+HIR"��С԰�վա�"+NOR"����������ط�������$w�����Ž������������޴���$n��$l",
	"force" : 310,
        "dodge" : 15,
	"parry" : 15,
	"damage": 65,
	"lvl" : 45,
	"skill_name" : "С԰�վ�",
	"damage_type":	"����"
]),
([      "action":"$NƮȻ�������࣬һ��"+WHT"������ҹ����"+NOR"��������б�ɣ���δ��أ�$w��ֱ��$n��$l",
	"force" : 390,
    "dodge" : 5,
	"parry" : 5,
    "damage": 75,
    "lvl" : 55,
    "skill_name" : "����ҹ��",
    "damage_type":  "����"
]),
([      "action":"$N��üһ�壬����б��һ����һ��"+HIW"�����¿��ˡ�"+NOR"��$w���ű��佣��ֱ��$n��$l",
        "force" : 410,
        "dodge" : 8,
		"parry" : 8,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "���¿���",
        "damage_type":  "����"
]),
([	"action":"$N����һ������Ȼһʽ"+HIC"��������Ӱ��"+NOR"��һ�ֺ�����������һ�ַ���һ����$w�����벻����λ�ô���$n��$l",
	"force" : 450,
    "dodge" : 10,
	"parry" : 10,
	"damage": 100,
	"lvl" : 70,
	"skill_name" : "������Ӱ",
	"damage_type":	"����"
]),
([	"action":"$N������Ť��üĿ���飬һʽ"+HIM"�����İ�ͨ��"+NOR"������$w��ƮƮ����$n��$l",
	"force" : 450,
    "dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 75,
	"skill_name" : "���İ�ͨ",
	"damage_type":	"����"
]),
([	"action":"$N����ƮȻ�߸�Ծ���ڰ��������һ������Ȼһʽ"+HIM"���������"+NOR"������$w��ȫ��������һ�����$n��$l",
	"force" : 650,
    "dodge" : 20,
	"parry" : 20,
	"damage": 100,
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
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
	level   = (int) me->query_skill("yunu-jianfa",1);
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
		return notify_fail("��ľ�����������Ů������\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunu-jianfa/" + action;
}